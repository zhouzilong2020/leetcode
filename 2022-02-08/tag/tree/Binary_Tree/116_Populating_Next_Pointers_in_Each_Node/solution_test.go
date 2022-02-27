package populatingnextpointersineachnode

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

func connect(root *Node) *Node {
	if root == nil {
		return root
	}

	solve(root.Left, root.Right)
	return root

}

func solve(node1 *Node, node2 *Node) {
	if node1 == nil || node2 == nil {
		return
	}
	node1.Next = node2

	solve(node1.Left, node1.Right)
	solve(node2.Left, node2.Right)
	solve(node1.Right, node2.Right)
}
