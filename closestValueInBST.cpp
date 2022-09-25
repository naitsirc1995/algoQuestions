#include <math.h>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
  int closestValue = tree->value;  
  while (tree != NULL){
    if (abs(target-closestValue) > abs(target - tree->value))
        closestValue = tree->value;
    
    if (target < tree->value)
        tree = tree->left;
    else
        tree = tree->right;
  }

  return closestValue;
}
