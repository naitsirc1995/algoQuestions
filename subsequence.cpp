#include "vector"
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  std::vector<int>::iterator sequence_cursor = begin(sequence);
  for (auto it = begin(array); it < end(array); it++ ){
    if (*it == *sequence_cursor){
        sequence_cursor++;        
    }

    if (sequence_cursor == end(sequence)){
        return true;
    }
  }

  return false;
}
