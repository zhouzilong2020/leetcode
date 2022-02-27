package convertbsttogreatertree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func traverse(root *TreeNode, curSum *int) {
	if root == nil {
		return
	}
	traverse(root.Right)

	curSum += root.Val
	root.Val = curSum

	traverse(root.Left)
}

func convertBST(root *TreeNode) *TreeNode {
	curSum := 0
	traverse(root, curSum)
	return root
}
