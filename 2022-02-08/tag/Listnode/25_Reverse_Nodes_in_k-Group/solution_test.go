package reversenodesinkgroup

import "testing"

type ListNode struct {
	Val  int
	Next *ListNode
}

var successor *ListNode

func reverseN(head *ListNode, n int) *ListNode {
	if n == 1 {
		successor = head.Next
		return head
	}

	last := reverseN(head.Next, n-1)
	head.Next.Next = head
	head.Next = successor
	return last
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	p, cnt := head, 1
	for p != nil && cnt < k {
		p = p.Next
		cnt++
	}
	if p == nil {
		return head
	}

	subHead := p.Next
	last := reverseN(head, k)
	head.Next = reverseKGroup(subHead, k)

	return last
}

func Test(t *testing.T) {
	testCase := &ListNode{1, &ListNode{2, &ListNode{3, nil}}}
	reverseKGroup(testCase, 2)

}
