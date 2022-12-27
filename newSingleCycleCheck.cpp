using namespace std;
#include<vector>
#include<unordered_set>
#include<iostream>

int modOperator(int number, int modulo){
    return ((number%modulo)+modulo)%modulo;
}
    

bool hasSingleCycle(vector<int> array) {
  // Write your code here.
  int index = array[0];
  int modulo = array.size();
  unordered_set<int> visitedIndices {0,modOperator(index,modulo)};
  index = modOperator(index,modulo);
  int iterations = 2;

  while (modOperator(index+array[index],modulo)!=0 ){    
    visitedIndices.insert(modOperator(index+array[index],modulo));
    index = modOperator(index+array[index],modulo);    
    if (iterations >= modulo){
        break;
    } else {
        iterations++;
    }
  }

  return (visitedIndices.size() == modulo) & (modOperator(index+array[index],modulo) ==0);
}