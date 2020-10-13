class solution24 {
  public static void main(String[] args) {
    System.out.println("as");
  }

  ListNode swapPairs(ListNode head) {
    if (head == null) {
      return head;
    }
    ListNode p1, p2, p3;
    p1 = head;
    p2 = head.next;
    // 仅仅有一个节点
    if (p2 == null) {
      return head;
    }
    p3 = head.next.next;

    head = p2;
    p2.next = p1;
    p2 = p3;
    // 仅有两个节点
    if (p2 == null) {
      p1.next = null;
      return head;
    }
    p3 = p2.next;

    while (p3 != null) {

      p1.next = p3;
      p1 = p2;

      p2 = p3.next;

      p3.next = p1;

      if (p2 == null) {
        p1.next = null;
        break;
      }
      p3 = p2.next;
    }
    p1.next = p2;

    return head;
  }
}
