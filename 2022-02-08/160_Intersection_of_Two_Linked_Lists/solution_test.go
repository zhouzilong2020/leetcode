package Intersection_of_Two_Linked_Lists

import (
	"testing"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	dummyHeadA := &ListNode{0, headA}
	dummyHeadB := &ListNode{0, headB}

	fastA, slowA := dummyHeadA.Next, dummyHeadA
	for fastA != nil {
		slowA = slowA.Next
		fastA = fastA.Next
	}
	tailA := slowA
	tailA.Next = headA

	fastB, slowB := dummyHeadB, dummyHeadB
	for fastB != nil && fastB.Next != nil {
		fastB = fastB.Next.Next
		slowB = slowB.Next

		if fastB == slowB { // found the intersection node
			break
		}
	}

	if fastB == nil || fastB.Next == nil { // if there is no intersection between two lists
		tailA.Next = nil
		return nil
	}

	// let slowA point back to the head
	slowB = dummyHeadB
	for slowB != fastB {
		slowB = slowB.Next
		fastB = fastB.Next
	}
	// restore the intersection
	tailA.Next = nil

	return slowB
}

func Test(t *testing.T) {

}
