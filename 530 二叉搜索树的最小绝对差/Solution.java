import java.util.ArrayList;
import java.util.PriorityQueue;
import java.lang.Math;

//题目中说明了二叉搜索树,左小右大!
class Solution530 {

  // 利用中序遍历
  private int prev = -1, min = Integer.MAX_VALUE;

  public void getDiff(TreeNode root) {
    if (root == null) {
      return;
    }

    getDiff(root.left);

    // 获得最小的那个数,之后开始比较
    if (prev == -1) {
      prev = root.val;
    } else {
      min = Math.min(min, root.val - prev);
      prev = root.val;
    }

    getDiff(root.right);
  }

  public int getMinimumDifference(TreeNode root) {
    getDiff(root);
    return min;
  }

  // 对于任意树均有效
  private int size;
  private ArrayList<Integer> val = new ArrayList<Integer>();

  public int getSizeVal(TreeNode root) {
    if (root == null) {
      return 0;
    } else {
      val.add(root.val);
      return getSizeVal(root.left) + getSizeVal(root.right);
    }
  }

  public int getMinimumDifference1(TreeNode root) {
    size = getSizeVal(root);
    PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>(size + 1);
    int min = Integer.MAX_VALUE;

    for (int i : val) {
      minHeap.add(i);
    }

    int len = minHeap.size();
    int num1, num2;
    for (int i = 0; i < len - 1; i++) {
      num1 = minHeap.poll();
      num2 = minHeap.peek();
      if (num2 - num1 < min) {
        min = num2 - num1;
        if (min == 0) {
          break;
        }
      }
    }
    return min;
  }
}