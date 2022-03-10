package courseschedule

func buildGraph(numCourses int, prerequisites *[][]int) [][]int {
	graph := make([][]int, numCourses)
	for i := 0; i < numCourses; i++ {
		graph[i] = make([]int, 0)
	}

	for _, prep := range *prerequisites {
		graph[prep[1]] = append(graph[prep[1]], prep[0])
	}

	return graph
}

func traverse(curPos int, gotCycle *bool, g *[][]int, isOnPath *[]bool, isVisited *[]bool) {
	if (*isOnPath)[curPos] {
		*gotCycle = true
	}
	if (*isVisited)[curPos] || *gotCycle {
		return
	}

	(*isOnPath)[curPos] = true
	(*isVisited)[curPos] = true
	for _, node := range (*g)[curPos] {
		traverse(node, gotCycle, g, isOnPath, isVisited)
	}

	(*isOnPath)[curPos] = false
}

func canFinish(numCourses int, prerequisites [][]int) bool {
	graph := buildGraph(numCourses, &prerequisites)
	isVisited := make([]bool, numCourses)
	isOnPath := make([]bool, numCourses)
	gotCycle := false
	for i := 0; i < numCourses; i++ {
		traverse(i, &gotCycle, &graph, &isOnPath, &isVisited)
	}
	return gotCycle
}
