package pancakesorting

func pancakeSort(arr []int) []int {
	lenArr := len(arr)
	res := make([]int, 0)
	for i := lenArr; 0 < i; i-- {
		curMaxPos := 0
		for ; arr[curMaxPos] != i; curMaxPos++ {

		}
		if curMaxPos+1 == i {
			continue
		}

		res = append(res, curMaxPos+1)
		res = append(res, lenArr)
	}
	return res
}
