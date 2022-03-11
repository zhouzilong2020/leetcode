package isgraphbipartite

type helper struct {
	g           [][]int
	visited     []bool
	color       []int
	isBipartite bool
}

func (h *helper) traverse(i int, c int) {
	if h.color[i] != 0 && h.color[i] != c {
		h.isBipartite = false
		return
	}

	if h.visited[i] || !h.isBipartite {
		return
	}

	h.color[i] = c
	h.visited[i] = true
	for _, node := range h.g[i] {
		// fmt.Println(i, "(",c,")-->", node,"(",-1*c,")",h.visited, h.color)
		h.traverse(node, -1*c)
	}
}

func isBipartite(graph [][]int) bool {

	helper := &helper{
		g:           graph,
		visited:     make([]bool, len(graph)),
		color:       make([]int, len(graph)),
		isBipartite: true,
	}
	for i := 0; i < len(graph); i++ {
		if !helper.visited[i] {
			helper.traverse(i, 1)
		}
	}
	return helper.isBipartite
}
