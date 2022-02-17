package mergetwosortedlists

import "testing"

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	head := ListNode{0, nil}
	p := &head
	for {
		if list1 == nil || list2 == nil {
			break
		}

		if list1.Val > list2.Val {
			p.Next = &ListNode{list2.Val, nil}
			list2 = list2.Next
		} else {
			p.Next = &ListNode{list1.Val, nil}
			list1 = list1.Next
		}
		p = p.Next
	}

	for ; list1 != nil; list1 = list1.Next {
		p.Next = &ListNode{list1.Val, nil}
		p = p.Next
	}

	for ; list2 != nil; list2 = list2.Next {
		p.Next = &ListNode{list2.Val, nil}
		p = p.Next
	}

	return head.Next
}

func Test(t *testing.T) {

	mergeTwoLists(&ListNode{0, nil}, &ListNode{1, nil})
}
