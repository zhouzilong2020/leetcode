package diameterofbinarytree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var maxDiameter int

func diameterOfBinaryTree(root *TreeNode) int {
	maxDiameter = 0
	solve(root)
	return maxDiameter
}

func solve(root *TreeNode) int {
	if root == nil {
		return 0
	}

	leftDepth := solve(root.Left)
	rightDepth := solve(root.Right)

	curDiameter := leftDepth + rightDepth
	if curDiameter > maxDiameter {
		maxDiameter = curDiameter
	}

	if leftDepth > rightDepth {
		return leftDepth + 1
	}
	return rightDepth + 1

}
