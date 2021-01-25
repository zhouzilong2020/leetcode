import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Solution {
  public List<Integer> preorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<Integer>();
    Stack<TreeNode> stack = new Stack<TreeNode>();
    TreeNode p;

    if (root == null) {
      return result;
    }

    stack.push(root);
    while (!stack.empty()) {
      p = stack.pop();
      if (p != null) {
        result.add(p.val);
        if (p.right != null) {
          stack.push(p.right);
        }
        if (p.left != null) {
          stack.push(p.left);
        }
      }
    }

    return result;
  }

  public static void main(String[] args) {
    System.out.println("adsgbahjdsfds");
  }
}