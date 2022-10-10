#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST &insert(int val) {
    // Write your code here.
    // Do not edit the return statement of this method.
    BST* currNode = this;
    while (currNode){
        if (val > currNode->value && currNode->right == nullptr){
            currNode->right = new BST(val);
            break;
        } else if (val < currNode->value && currNode->left == nullptr){
            currNode-> left = new BST(val);
            break;
        }

        if (val > currNode->value) currNode = currNode->right;
        else if (val < currNode->value) currNode = currNode->left;
    }
    return *this;
  }

  bool contains(int val) {
    // Write your code here.
    BST* currNode = this;

    while (currNode){
        if (currNode->value == val){
            return true;            
        } else if (val >= currNode->value){
            currNode = currNode->right;
        } else if (val < currNode->value) {
            currNode = currNode->left;
        }
    }
    
    return false;
  }

  BST &remove(int val) {
    // Write your code here.
    // Do not edit the return statement of this method.
    
    return *this;
  }

  int getMinValue(){
    BST* currNode = this;
    while (currNode->left){
      currNode = currNode->left;
    }
    return currNode->value;
  }

  vector<BST*> getNodeRemoveData(int val, BST* parent){
    BST* currNode = this;
    while (currNode){
      if (currNode->value == val) break;

      parent = currNode;
      if (val >= currNode->value ){
        currNode = parent->right;
      } else if (val < currNode->value ){
        currNode = parent->left;
      }
    }

    return vector<BST*> {parent,currNode};
  }
};
