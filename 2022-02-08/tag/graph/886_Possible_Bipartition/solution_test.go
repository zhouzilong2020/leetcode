package possiblebipartition

type helper struct {
	g           [][]int
	dislikes    [][]int
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
		h.traverse(node, -1*c)
	}
}

func (h *helper) buildGraph(n int) {
	h.g = make([][]int, n)
	for i := 0; i < n; i++ {
		h.g[i] = make([]int, 0)
	}

	for _, edge := range h.dislikes {
		v1, v2 := edge[0]-1, edge[1]-1
		h.g[v1] = append(h.g[v1], v2)
		h.g[v2] = append(h.g[v2], v1)
	}

}

func possibleBipartition(n int, dislikes [][]int) bool {

	helper := &helper{
		dislikes:    dislikes,
		visited:     make([]bool, n),
		color:       make([]int, n),
		isBipartite: true,
	}
	helper.buildGraph(n)

	for i := 0; i < n; i++ {
		if !helper.visited[i] {
			helper.traverse(i, 1)
		}
	}

	return helper.isBipartite

}
