package kthsmallestelementinabst

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func traverse(root *TreeNode, k int) int {
	if root == nil {
		return -1
	}

	traverse(root.Left, k)
	k -= 1
	if k == 0 {
		return root.Val
	}
	traverse(root.Right, k)
	return 0
}

func kthSmallest(root *TreeNode, k int) int {

	return traverse(root, k)
}
