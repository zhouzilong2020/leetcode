class Solution {

  public ListNode removeNthFromEnd(ListNode head, int n) {
    if (head == null) {
      return head;
    }
    ListNode fast = head, slow = head;
    for (int i = 0; i < n; i++) {
      fast = fast.next;
    }
    if (fast == null) {// 删除的是头节点!
      head = head.next;
      return head;
    }
    // 删除的是中间节点
    while (fast.next != null) {
      fast = fast.next;
      slow = slow.next;
    }
    slow.next = slow.next.next;
    return head;
  }

}