package Linked_List_Cycle

import "testing"

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	dummyHead := &ListNode{0, head}
	fast, slow := dummyHead, dummyHead
	for fast != nil {
		slow = slow.Next
		fast = fast.Next
		if fast != nil {
			fast = fast.Next
		}

		if fast == slow {
			return true
		}
	}

	return false
}

func Test(t *testing.T) {

}
