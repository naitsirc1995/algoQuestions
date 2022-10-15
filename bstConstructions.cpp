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
        if (val >= currNode->value && currNode->right == nullptr){
            currNode->right = new BST(val);
            break;
        } else if (val < currNode->value && currNode->left == nullptr){
            currNode-> left = new BST(val);
            break;
        }

        if (val >= currNode->value) currNode = currNode->right;
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

  BST &remove(int val, BST* parent = nullptr ){
    if (val < value){
      if (left != nullptr){
        left->remove(val,this);
      }
    } else if (val > value){
      if (right != nullptr){
        right->remove(val,this);
      }
    } else {
      if (left != nullptr && right != nullptr){
        value = right->getMinValue();
        right->remove(value,this);
      } else if (parent == nullptr){
        if (left!= nullptr){
          value = left->value;
          right = left->right;
          left = left->left;
        } else if (right != nullptr){
          value = right->value;
          left = right->left;
          right = right->right;
        } else {

        }
      } else if (parent->left == this){
        parent->left = left != nullptr ?  left : right;
      } else if (parent->right == this){
        parent->right = left != nullptr ? left : right;
      }
    }

    return *this; 
      
  };  
  

  // This method will return the min value of a node
  int getMinValue(){
    if (left == nullptr){
      return value;
    } else {
      return left->getMinValue();
    }
  };  
  
};
