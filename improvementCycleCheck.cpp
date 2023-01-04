using namespace std;
#include<vector>
#include<unordered_set>
#include<iostream>

int modOperator(int number, int modulo){
    return ((number%modulo)+modulo)%modulo;
}
    

bool hasSingleCycle(vector<int> array) {
  // Write your code here.
  int index = 0;
  int modulo = array.size();
  int iterations = 0;
  unordered_set<int> visitedIndices;
  
  do {
        visitedIndices.insert(index);
        index = modOperator(array[index]+index,modulo);
        iterations++;
        if (iterations==modulo) break;
  } while (index != 0);

  return (visitedIndices.size() == modulo) & (index ==0);
}