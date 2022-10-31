import java.util.*;

class Program {
  public static boolean validateBst(BST tree) {
    BST curr = tree;
    if (tree.left.value < curr.value && tree.right.value > curr.value){
        validateBst(tree.left);
        validateBst(tree.right);
    }
    return false;
  }

  static class BST {
    public int value;
    public BST left;
    public BST right;

    public BST(int value) {
      this.value = value;
    }
  }
}
