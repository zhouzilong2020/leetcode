import java.util.Stack;

class Solution {
  public int sumNumbers(TreeNode root) {
    // int cnt = 0, tem = 0;
    // Stack<TreeNode> stack = new Stack<>();
    // Stack<TreeNode> his = new Stack<>();
    // TreeNode top;
    // if (root == null) {
    // return cnt;
    // }
    // stack.push(root);
    // his.push(root);

    // while (!stack.empty()) {
    // top = stack.pop();
    // tem = tem * 10 + top.val;
    // if (top.left == null && top.right == null) {
    // // 叶子结点
    // cnt += tem;
    // tem = (tem - his.pop().val) / 10;
    // } else {
    // // 非叶子结点
    // if (top.right != null) {
    // his.push(top.right);
    // stack.push(top.right);
    // }
    // if (top.left != null) {
    // his.push(top.right);
    // stack.push(top.left);
    // }
    // }
    // }
    // return cnt;
    int cnt = 0;
    return count(root, root.val);
  }

  int count(TreeNode root, int cnt) {
    if (root == null) {
      return 0;
    }
    if (root.left == null && root.right == null) {
      // 叶子结点
      return cnt;
    } else if (root.left != null && root.right != null) {
      return count(root.left, cnt * 10 + root.left.val) + count(root.right, cnt * 10 + root.right.val);
    } else if (root.left != null) {
      return count(root.left, cnt * 10 + root.left.val);
    } else {
      return count(root.right, cnt * 10 + root.right.val);
    }
  }

}