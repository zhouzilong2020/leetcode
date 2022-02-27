package searchinabinarysearchtree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}


func searchBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return
	}
	if root.Val < root {
		return searchBST(root.Right, val)
	} else if {
		return searchBST(root.Left, val)
	} else{
		return root
	}

}
