package validatebinarysearchtree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func traverse(root *TreeNode, last *int) bool {
	if root == nil {
		return true
	}

	traverse(root.Left, last)
	if last >= root.Val {
		return false
	}
	*last = root.Val
	traverse(root.Right, last)

	return true
}

func isValidBST(root *TreeNode) bool {
	last := nil
	return traverse(root, &last)
}

func Test(t *testing.T) {

}
