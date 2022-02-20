package palindromelinkedlist

import (
	"fmt"
	"testing"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

var left *ListNode

func traverse(head *ListNode) bool {
	if head == nil {
		return true
	}

	res := traverse(head.Next)

	if left.Val == head.Val && res {
		left = left.Next
		return true
	}
	return false
}

func isPalindrome_Recursive(head *ListNode) bool {
	left = head
	return traverse(head)
}

func reverse(head *ListNode) *ListNode {
	var pre, cur *ListNode
	pre = nil
	cur = head
	for cur != nil {
		next := cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	head.Next = nil
	return pre
}

func isPalindrome(head *ListNode) bool {
	if head.Next == nil {
		return true
	}

	fast, slow := head, head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}
	if fast != nil {
		slow = slow.Next
	}

	tail := reverse(slow)
	end := tail
	front := head

	for end != nil {
		if front.Val != end.Val {
			break
		}

		front = front.Next
		end = end.Next
	}

	reverse(tail)
	return end == nil
}

func Test(t *testing.T) {
	head := &ListNode{1, nil}
	fmt.Println(isPalindrome(head))

}
