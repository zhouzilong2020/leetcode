package constructbinarytreefrompreorderandinordertraversal

import "testing"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 || len(inorder) == 0 {
		return nil
	}
	curNodeVal := preorder[0]

	root := &TreeNode{Val: curNodeVal}
	nextPos := -1
	for i, num := range inorder {
		if num == curNodeVal {
			nextPos = i
			break
		}
	}

	root.Left = buildTree(preorder[1:], inorder[:nextPos])
	root.Right = buildTree(preorder[nextPos+1:], inorder[nextPos+1:])

	return root
}

func Test(t *testing.T) {

	preorder := []int{3, 9, 20, 15, 7}
	inorder := []int{9, 3, 15, 20, 7}
	buildTree(preorder, inorder)
}
