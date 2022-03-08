package countcompletetreenodes

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func countNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}
	// speed up
	leftH := 1
	for l := root.Left; l != nil; l = l.Left {
		leftH++
	}

	rightH := 1
	for r := root.Right; r != nil; r = r.Right {
		rightH++
	}

	// perfect binary tree
	if rightH == leftH {
		return int(math.Pow(2, float64(rightH))) + 1
	}

	left := countNodes(root.Left)
	right := countNodes(root.Right)

	return left + right + 1
}
