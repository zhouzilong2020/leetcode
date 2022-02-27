package deletenodeinabst

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}

	if root.Val == key {
		if root.Left == nil {
			return root.Right
		} else if root.Right == nil {
			return root.Left
		} else {
			minNode := root.Right
			for minNode.Left != nil {
				minNode = minNode.Left
			}
			root.Right = deleteNode(root.Right, minNode.Val)
			root.Val = minNode.Val
		}

	} else if root.Val < key {
		root.Right = deleteNode(root.Right, key)
	} else {
		root.Left = deleteNode(root.Left, key)
	}

	return root
}
