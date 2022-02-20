package Middle_of_the_Linked_List

import "testing"

type ListNode struct {
	Val  int
	Next *ListNode
}

func middleNode(head *ListNode) *ListNode {
	dummyHead := &ListNode{0, head}
	fast, slow := dummyHead, dummyHead
	for fast != nil {
		slow = slow.Next
		fast = fast.Next
		if fast != nil {
			fast = fast.Next
		}
	}
	// x 1
	//   |
	//     |
	return slow
}

func Test(t *testing.T) {
	middleNode(&ListNode{1, nil})
}
