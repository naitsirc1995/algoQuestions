import java.util.*;

class Program {
  // This is the class of the input root. Do not edit it.
  public static class BinaryTree {
    int value;
    BinaryTree left;
    BinaryTree right;

    BinaryTree(int value) {
      this.value = value;
      this.left = null;
      this.right = null;
    }
  }

  public static List<Integer> branchSums(BinaryTree root) {
    // Write your code here.
    ArrayList<Integer> resultList = new ArrayList<Integer>();
    sumFunc(root,0, resultList);
    return resultList;
  }


  public static void sumFunc(BinaryTree tree, int resultSum, ArrayList<Integer> resultList ){
    if (tree == null) return;

    if ( tree.left == null && tree.right == null ){
        resultList.add(resultSum+tree.value);
    }

    sumFunc(tree.left, resultSum + tree.value , resultList);
    sumFunc(tree.right, resultSum + tree.value , resultList);

  }
}