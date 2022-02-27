package maximumbinarytree

import "testing"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func constructMaximumBinaryTree(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	curMaxPos, curMax := -1, -1
	for i, num := range nums {
		if num > curMax {
			curMaxPos = i
			curMax = num
		}
	}

	root := &TreeNode{Val: curMax}
	root.Left = constructMaximumBinaryTree(nums[:curMaxPos])
	root.Right = constructMaximumBinaryTree(nums[curMaxPos+1:])

	return root
}

func Test(t *testing.T) {
	nums := []int{3, 2, 1, 6, 0, 5}
	constructMaximumBinaryTree(nums)
}
