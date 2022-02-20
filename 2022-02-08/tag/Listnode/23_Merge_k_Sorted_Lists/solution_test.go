package mergeksortedlists

import (
	"container/heap"
	"testing"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// this solution will first build up a minHeap, then try to pop out element from it.
// which may be ineffective when the size is to large.(a lots of time may be wasted during the set up phase)
func mergeKListsWithIntHeap(lists []*ListNode) *ListNode {
	intHeap := &IntHeap{}
	heap.Init(intHeap)
	for _, list := range lists {
		for p := list; p != nil; p = p.Next {
			heap.Push(intHeap, p.Val)
		}
	}

	head := &ListNode{0, nil}
	p := head
	for intHeap.Len() != 0 {
		p.Next = &ListNode{heap.Pop(intHeap).(int), nil}
		p = p.Next
	}

	return head.Next
}

type MinHeap []*ListNode

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(*ListNode))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// this solution only keep the head val of each list, and will update the head val after an element is popped out from the list
// which will save a lots of time when maintaining head structure
func mergeKLists(lists []*ListNode) *ListNode {
	minHeap := &MinHeap{}
	heap.Init(minHeap)
	for _, head := range lists {
		if head != nil {
			heap.Push(minHeap, head)
		}
	}

	head := &ListNode{0, nil}
	p := head
	for minHeap.Len() != 0 {
		minListHead := heap.Pop(minHeap).(*ListNode)
		// if the list popped still has node, we update the val of this list stored in the heap
		if minListHead.Next != nil {
			heap.Push(minHeap, minListHead.Next)
		}

		// we alloc a new space for the merged list, thus more space and time are consumed
		p.Next = &ListNode{minListHead.Val, nil}

		p = p.Next
	}

	return head.Next
}

func mergeKListsInplace(lists []*ListNode) *ListNode {
	minHeap := &MinHeap{}
	heap.Init(minHeap)
	for _, head := range lists {
		if head != nil {
			heap.Push(minHeap, head)
		}
	}

	head := &ListNode{0, nil}
	p := head
	for minHeap.Len() != 0 {
		minListHead := heap.Pop(minHeap).(*ListNode)
		if minListHead.Next != nil {
			heap.Push(minHeap, minListHead.Next)
		}
		// we do not alloc a new space for the merged list
		p.Next = minListHead
		p = p.Next
	}

	return head.Next
}

func Test(t *testing.T) {
	l := make([]*ListNode, 0)
	mergeKLists(l)
}
