#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int> &vector) {
    // Write your code here.
    return {};
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {    
  }

  void siftUp(int currentIdx, vector<int> &heap) {
    if (currentIdx<=0) return;

    int parentIdx = (currentIdx-1)/2;

    if (heap.at(parentIdx)>heap.at(currentIdx)){
        swap(heap[parentIdx],heap[currentIdx]);
        siftUp(parentIdx,heap);
    }
  }

  int peek() {
    // Write your code here.
    return heap[0];
  }

  int remove() {
    // Write your code here.
    return -1;
  }

  void insert(int value) {
    heap.push_back(value);
    siftUp(heap.size()-1,heap);
  }
};
