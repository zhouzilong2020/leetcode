package Remove_Nth_Node_From_End_of_List

import "testing"

type ListNode struct {
	Next *ListNode
	Val  int
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummyHead := &ListNode{Next: head, Val: 0}

	fast, slow := dummyHead, dummyHead
	for i := -1; i < n; i++ {
		fast = fast.Next
	}

	for fast != nil {
		fast = fast.Next
		slow = slow.Next
	}

	slow.Next = slow.Next.Next
	return dummyHead.Next
}

func Test(t *testing.T) {
	removeNthFromEnd(&ListNode{&ListNode{&ListNode{nil, 2}, 1}, 0}, 1)
	removeNthFromEnd(&ListNode{&ListNode{&ListNode{nil, 2}, 1}, 0}, 2)
	removeNthFromEnd(&ListNode{&ListNode{&ListNode{nil, 2}, 1}, 0}, 3)
	// 0 1 2 3

}
