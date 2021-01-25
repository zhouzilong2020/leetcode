class Solution {
  public void reorderList(ListNode head) {
    if (head == null) {
      return;
    }
    ListNode fast = head, slow = head;
    // 使用快慢指针使得慢指针指向中间节点
    while (fast.next != null) {
      fast = fast.next.next;
      slow = slow.next;
    }
    // fast != null 说明是奇数个数, slow刚好指向中间节点
    if (fast != null) {
      slow = slow.next;
    }

    // 反转后半部部分节点
    ListNode p1 = slow, p2 = slow.next, p3, tail; // tail
    if (p2 == null) {
      // 仅仅有一个节点的情况, 不需要操作
      tail = p1;
    } else{
      // 有多余一个节点
      p3 = slow.next.next;
      p1.next = null; // 处理头节点
      while (p3 != null) {
        p2.next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3.next;
      }
      p2.next = p1; // 处理最后一个节点
      tail = p2;
    }
    
    // 将节点进行插入
    p1 = head;
    p2 = tail;
    p3 = p2.next;
    while(p3 != null){
      p2.next = p1.next;
      p1.next = p2;
      p2 = p3;
      p3 = p3.next;
      p1 = p1.next.next;
    }
    // 处理最后一个节点
    p2.next= p1.next;
    p1.next = p2;
    p1 = p1.next.next;
    // 如果是奇数个节点
    if(p1 != null){
      p1.next = null;
    }

  }

  // public static void main(String[] args) {
  //   System.out.println("asdjbfjhkasdbflisdu");
  // }
}