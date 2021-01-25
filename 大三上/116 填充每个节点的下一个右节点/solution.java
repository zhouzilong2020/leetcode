import java.util.LinkedList;
import java.util.Queue;

class Solution {

  public Node connect1(Node root) {
    if (root == null) {
      return null;
    }
    Node leftMost = root;
    while (leftMost.left != null) {
      Node head = leftMost;
      while (head != null) {
        head.left.next = head.right;
        if (head.next != null) {
          head.right.next = head.next.left;
        }
        head = head.next;
      }
      leftMost = leftMost.left;
    }
    return root;
  }

  public static Node connect(Node root) {
    if (root == null) {
      return root;
    }

    Node leftMost = root, localHead;
    while (leftMost.left != null) {
      // localHead指向某一层的某一个节点. leftMost总保持在某一层次的最左边的节点;
      localHead = leftMost;
      // 当还有下一层时执行
      while (localHead != null) {
        localHead.left.next = localHead.right;
        if (localHead.next != null) {
          localHead.right.next = localHead.next.left;
        }
        localHead = localHead.next;
      }
      leftMost = leftMost.left;
    }

    return root;
  }

  public static Node connectQueue(Node root) {
    // 没有节点
    if (root == null) {
      return root;
    }
    // 仅有一个节点
    if (root.left == null) {
      return root;
    }
    Queue<Node> queue = new LinkedList<Node>();
    Node p1, p2;
    int pos = 4, i = 1; // 记录二叉树的位置, 用于判断某一节点时候还有后续节点
    queue.offer(root.left);
    queue.offer(root.right);

    while (!queue.isEmpty()) {
      i++;

      p1 = queue.poll();
      p2 = queue.peek();
      if (i != pos - 1) {
        // 非末尾元素
        p1.next = p2;
      } else {
        // 末尾元素
        pos *= 2;
      }
      if (p1.left == null) { // 说明到达了最后一层节点,不需要继续压入队列
        continue;
      }
      queue.offer(p1.left);
      queue.offer(p1.right);

    }

    return root;
  }

  public static void main(String[] args) {
    // System.out.println("asd");
  }
}