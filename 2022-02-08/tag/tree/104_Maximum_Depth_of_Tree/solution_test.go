package maximumdepthoftree

import (
	c "../../../common"
)

func maxDepth(root *c.TreeNode) int {
	if root == nil {
		return 0
	}
	left, right := maxDepth(root.Left), maxDepth(root.Right)
	if left > right {
		return left + 1
	}
	return right + 1

}
