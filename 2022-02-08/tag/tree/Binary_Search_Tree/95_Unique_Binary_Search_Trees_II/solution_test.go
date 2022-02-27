package uniquebinarysearchtreesii

import "testing"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func getSubtreeSet(low int, high int, memo [][][]*TreeNode) []*TreeNode {
	if low > high {
		null := make([]*TreeNode, 1)
		null[0] = nil
		return null
	}

	if memo[low][high] != nil {
		return memo[low][high]
	}

	res := make([]*TreeNode, 0)
	for i := low; i <= high; i++ {
		left := getSubtreeSet(low, i-1, memo)
		right := getSubtreeSet(i+1, high, memo)
		for _, lTree := range left {
			for _, rTree := range right {
				root := &TreeNode{Val: i, Left: lTree, Right: rTree}
				res = append(res, root)
			}
		}
	}

	if memo[low][high] == nil {
		memo[low][high] = res
	}

	return res
}

func generateTrees(n int) []*TreeNode {
	memo := make([][][]*TreeNode, n+1)
	// var memo [n + 1][n + 1][]*TreeNode
	for i := 0; i <= n; i++ {
		memo[i] = make([][]*TreeNode, n+1)
	}
	for i := 1; i <= n; i++ {
		temp := make([]*TreeNode, 1)
		temp[0] = &TreeNode{Val: i}
		memo[i][i] = temp
	}
	return getSubtreeSet(1, n, memo)
}

func Test(t *testing.T) {
	generateTrees(2)
}
