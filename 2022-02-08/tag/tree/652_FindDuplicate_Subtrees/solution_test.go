package findduplicatesubtrees

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func traverse(memo map[string]int, res []*TreeNode, root *TreeNode) string {
	if root == nil {
		return ""
	}
	leftStr := traverse(memo, res, root.Left)
	rightStr := traverse(memo, res, root.Right)
	curStr := fmt.Sprintf("%s,%s,%s", leftStr, root.Val, rightStr)

	memo[curStr] += 1
	if memo[curStr] == 2 {
		res = append(res, root)
	}
	return curStr
}

func findDuplicateSubtrees(root *TreeNode) []*TreeNode {
	memo := make(map[string]int, 0)
	res := make([]*TreeNode, 0)
	traverse(memo, res, root)
	return res
}
