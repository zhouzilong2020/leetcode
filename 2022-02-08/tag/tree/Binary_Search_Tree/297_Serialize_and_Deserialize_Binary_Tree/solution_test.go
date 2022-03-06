package serializeanddeserializebinarytree

import (
	"fmt"
	"strconv"
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

func traverseSerialize(root *TreeNode, b *strings.Builder) {
	if root == nil {
		b.WriteString(",#")
		return
	}
	b.WriteString(fmt.Sprintf(",%v", root.Val))

	traverseSerialize(root.Left, b)
	traverseSerialize(root.Right, b)
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	var b strings.Builder
	traverseSerialize(root, &b)
	return b.String()
}

func traverseDeserialize(nodeString []string, curPos *int) *TreeNode {
	*curPos++

	if nodeString[*curPos] == "#" {
		return nil
	}

	intVal, _ := strconv.Atoi(nodeString[*curPos])
	root := &TreeNode{Val: intVal}

	root.Left = traverseDeserialize(nodeString, curPos)
	root.Right = traverseDeserialize(nodeString, curPos)

	return root
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	nodeString := strings.Split(data, ",")
	curPos := 0
	return traverseDeserialize(nodeString, &curPos)
}
