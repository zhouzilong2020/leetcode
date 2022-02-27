package flattenbinarytreetolinkedlist

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func flatten(root *TreeNode) {
	if root == nil {
		return
	}

	flatten(root.Left)
	flatten(root.Right)
	left, right := root.Left, root.Right

	root.Right, root.Left = left, nil

	p := root
	for p.Right != nil {
		p = p.Right
	}
	p.Right = right

}
