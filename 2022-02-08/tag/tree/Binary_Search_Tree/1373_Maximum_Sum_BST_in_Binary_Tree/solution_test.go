package maximumsumbstinbinarytree

import (
	"math"
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxSumBST(root *TreeNode, curMax *int) (bool, int, int, int) {
	if root == nil {
		return true, 0, 50000, -50000
	}

	lValid, lSum, lMin, lMax := maxSumBST(root.Left, curMax)
	rValid, rSum, rMin, rMax := maxSumBST(root.Right, curMax)

	if lValid && rValid {
		if lMax >= root.Val || root.Val >= rMin {
			return false, 0, 0, 0
		}
		curVal := root.Val + lSum + rSum
		if curVal > *curMax {
			*curMax = curVal
		}
		return true, curVal, int(math.Min(float64(lMin), float64(root.Val))), int(math.Max(float64(rMax), float64(root.Val)))
	}

	return false, 0, 0, 0
}

func Test(t *testing.T) {

	curMax := 0
	maxSumBST(nil, &curMax)
}
