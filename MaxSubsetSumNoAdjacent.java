import java.util.*;

class Program {
  public static int maxSubsetSumNoAdjacent(int[] array) {
    if (array.length == 0) return 0;
    if (array.length == 1) return array[0];
    if (array.length == 2) return Math.max(array[0], array[1]);
    int[]  maxArray = new int[3];
    maxArray[0] = array[0];
    maxArray[1] = Math.max(array[0], array[1]);
    int j = 2;
    for (;j<array.length;j++){
      maxArray[2] = Math.max(array[j]+maxArray[0], maxArray[1]);
      maxArray[0] = maxArray[1];
      maxArray[1] = maxArray[2];
      
    }

    return maxArray[2];
  }
}