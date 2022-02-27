package uniquebinarysearchtrees

func solve(n int, memo []int) int {
	if memo[n] != 0 {
		return memo[n]
	}

	curCnt := 0
	for i := 0; i < n; i++ {
		left := solve(i, memo)
		right := solve(n-i-1, memo)
		curCnt += left * right
	}
	memo[n] = curCnt
	return curCnt
}

func numTrees(n int) int {
	memo := make([]int, n+1)
	memo[0], memo[1] = 1, 1
	solve(n, memo)
	return memo[n]
}
