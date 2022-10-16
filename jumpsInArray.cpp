using namespace std;
#include<iostream>
#include<vector>


int mod(int x, int y){
    return (y+(x%y))%y;
}

bool hasSingleCycle(vector<int> array) {    
  int currIdx = 0, count = 0, n = array.size();
  while (true){
    count++;
    currIdx = mod(currIdx+array[currIdx],n);
    if (currIdx==0){
        return count == n;
    }
    if (count == n){
        return false;
    }
  } 
}