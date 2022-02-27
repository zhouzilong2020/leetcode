package constructbinarytreefrominorderandpostordertraversal

import "testing"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(inorder []int, postorder []int) *TreeNode {
	if len(inorder) == 0 || len(postorder) == 0 {
		return nil
	}

	curNodeVal := postorder[len(postorder)-1]
	curPos := -1
	for i, num := range inorder {
		if num == curNodeVal {
			curPos = i
			break
		}
	}

	root := &TreeNode{Val: curNodeVal}

	//    fmt.Println(curNodeVal,curPos,inorder,postorder)
	root.Right = buildTree(inorder[curPos+1:], postorder[curPos:len(postorder)-1])
	root.Left = buildTree(inorder[:curPos], postorder[:curPos])

	return root
}

func Test(t *testing.T) {
	inorder := []int{9, 3, 15, 20, 7}
	postorder := []int{9, 15, 7, 20, 3}

	buildTree(inorder, postorder)
}
