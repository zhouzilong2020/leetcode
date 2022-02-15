package luckynumber

import (
	"fmt"
	"testing"
)

func luckyNumbers(matrix [][]int) []int {
	m := len(matrix)
	n := len(matrix[0])

	biggestMatrix, smallestMatrix := make([][]bool, m), make([][]bool, m)
	for i := 0; i < m; i++ {
		biggestMatrix[i] = make([]bool, n)
		smallestMatrix[i] = make([]bool, n)
	}

	var tempPos int
	for i := 0; i < m; i++ {
		tempPos = 0
		for j := 0; j < n; j++ {
			if matrix[i][j] < matrix[i][tempPos] {
				tempPos = j
			}
		}
		biggestMatrix[i][tempPos] = true
	}
	for i := 0; i < n; i++ {
		tempPos = 0
		for j := 0; j < m; j++ {
			if matrix[j][i] > matrix[tempPos][i] {
				tempPos = j
			}
		}
		smallestMatrix[tempPos][i] = true
	}

	res := make([]int, 0)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if biggestMatrix[i][j] && smallestMatrix[i][j] {
				res = append(res, matrix[i][j])
			}
		}
	}
	return res
}

func Test(t *testing.T) {
	rows1 := []int{3, 7, 8}
	rows2 := []int{9, 11, 13}
	rows3 := []int{15, 16, 17}

	matrix := make([][]int, 3)
	matrix[0] = rows1
	matrix[1] = rows2
	matrix[2] = rows3

	fmt.Println(luckyNumbers(matrix))
}
