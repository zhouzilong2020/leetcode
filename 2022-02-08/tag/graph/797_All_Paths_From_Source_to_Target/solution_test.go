package allpathsfromsourcetotarget

func traverse(graph *[][]int, curPos int, curPath *[]int, pathList *[][]int) {
	*curPath = append(*curPath, curPos)

	if curPos == len(*graph)-1 {
		curPathCopy := []int{}
		curPathCopy = append(curPathCopy, *curPath...)
		*pathList = append(*pathList, curPathCopy)
	}

	for _, adjacent := range (*graph)[curPos] {
		traverse(graph, adjacent, curPath, pathList)
	}

	*curPath = (*curPath)[0 : len(*curPath)-1]
}
func allPathsSourceTarget(graph [][]int) [][]int {
	var pathList [][]int
	var curPath []int
	traverse(&graph, 0, &curPath, &pathList)
	return pathList
}
