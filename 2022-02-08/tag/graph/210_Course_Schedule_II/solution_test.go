package coursescheduleii

func buildGraph(numCourses int, prerequisites *[][]int) [][]int {
	graph := make([][]int, numCourses)
	for i := 0; i < numCourses; i++ {
		graph[i] = make([]int, 0)
	}

	for _, prep := range *prerequisites {
		graph[prep[0]] = append(graph[prep[0]], prep[1])
	}

	return graph
}

func traverse(curPos int, gotCycle *bool, g *[][]int, isOnPath *[]bool, isVisited *[]bool, visit *[]int) {
	if (*isOnPath)[curPos] {
		*gotCycle = true
	}
	if (*isVisited)[curPos] || *gotCycle {
		return
	}

	(*isOnPath)[curPos] = true
	(*isVisited)[curPos] = true
	for _, node := range (*g)[curPos] {
		traverse(node, gotCycle, g, isOnPath, isVisited, visit)
	}

	*visit = append(*visit, curPos)
	(*isOnPath)[curPos] = false
}

func findOrder(numCourses int, prerequisites [][]int) []int {
	graph := buildGraph(numCourses, &prerequisites)
	isVisited := make([]bool, numCourses)
	isOnPath := make([]bool, numCourses)
	visit := make([]int, 0)
	gotCycle := false
	for i := 0; i < numCourses; i++ {
		traverse(i, &gotCycle, &graph, &isOnPath, &isVisited, &visit)
	}

	if gotCycle {
		return []int{}
	}

	return visit
}
