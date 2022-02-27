package constructbinarytreefrompreorderandpostordertraversal

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
	if len(preorder) == 0 || len(postorder) == 0 {
		return nil
	}

	curNodeVal := preorder[0]
	root := &TreeNode{Val: curNodeVal}

	if len(preorder) == 1 {
		return root
	}

	nextNodeVal := preorder[1]
	nextPos := -1
	for i, num := range postorder {
		if num == nextNodeVal {
			nextPos = i
			break
		}
	}

	root.Left = constructFromPrePost(preorder[1:nextPos+1], postorder[:nextPos+1])
	root.Right = constructFromPrePost(preorder[nextPos+2:], postorder[nextPos+1:len(postorder)-1])

	return root
}
