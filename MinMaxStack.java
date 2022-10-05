import java.util.*;

class Program {
  // Feel free to add new properties and methods to the class.
  

  static class MinMaxStack {
    static private ArrayList<Integer> min = new ArrayList<Integer>();
    static private ArrayList<Integer> max = new ArrayList<Integer>();
    private ArrayList<Integer> stack = new ArrayList<Integer>();

    public int peek() {      
      return stack.get(stack.size()-1);
    }

    public int pop() {
      if (min.get(min.size()-1) == peek()) 
        min.remove(min.size()-1);
      
      if (max.get(max.size()-1) == peek())
        max.remove(max.size()-1);
                
      return stack.remove(stack.size()-1);
    }

    public void push(Integer number) {
        if (stack.isEmpty()){
            min.add(number);
            max.add(number);
        } else {
            if (number <= min.get(min.size()-1))
                min.add(number);
            if (number >= max.get(max.size()-1))
                max.add(number);
        }      

        stack.add(number);
    }

    public int getMin() {      
      return min.get(min.size()-1);
    }

    public int getMax() {
      // Write your code here.
      return max.get(max.size()-1);
    }
  }
}
