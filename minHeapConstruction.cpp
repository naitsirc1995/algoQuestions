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
    
    int firstParentIdx = (vector.size()-2)/2;
    for (int i = firstParentIdx; i>=0; i--){
      siftDown(i,vector.size()-1,vector);
    }

    return vector;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
    const int leftIdx = 2*currentIdx+1;
    if (leftIdx>endIdx) return;
    
    const int rightIdx = leftIdx+1;    
    const int nextIdx = [&](){
      if ( rightIdx > endIdx || heap[leftIdx] < heap[rightIdx] )
        return leftIdx;
      return rightIdx;
    }();

    if (heap[currentIdx] > heap[nextIdx]){
      swap(heap[nextIdx],heap[currentIdx]);
      currentIdx = nextIdx;
      siftDown(currentIdx,endIdx,heap);
    }
  }

  void siftUp(int currentIdx, vector<int> &heap) {
    if (currentIdx<=0) return;

    int parentIdx = (currentIdx-1)/2;

    if (heap[parentIdx]>heap[currentIdx]){
        swap(heap[parentIdx],heap[currentIdx]);
        siftUp(parentIdx,heap);
    }
  }

  int peek() {
    // Write your code here.
    return heap[0];
  }

  int remove() {
    int tmp = heap[0];
    heap[0] = heap[heap.size()-1];
    heap.erase(end(heap)-1);    
    siftDown(0,heap.size()-1,heap);
    return tmp;
  }

  void insert(int value) {
    heap.push_back(value);
    siftUp(heap.size()-1,heap);
  }
};
