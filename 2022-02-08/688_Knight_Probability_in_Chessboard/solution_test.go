package knightprobabilityinchessboard

import (
	"math"
	"testing"
)

type pos struct{ x, y int }

var dirs = []struct{ i, j int }{{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}}

// the complexity in time is O(k * 8 * n^2); space O(k^2)
func knightProbability(n int, k int, row int, column int) float64 {
	curPosMap := make(map[pos]float64)
	curPosMap[pos{row, column}] = 1

	for i := 0; i < k; i++ {
		newPosMap := make(map[pos]float64)
		for p, cnt := range curPosMap {
			for _, pm := range dirs {
				newPos := pos{p.x + pm.i, p.y + pm.j}
				if 0 <= newPos.x && newPos.x < n && 0 <= newPos.y && newPos.y < n {
					if _, ok := newPosMap[newPos]; !ok {
						newPosMap[newPos] = float64(cnt)
					} else {
						newPosMap[newPos] += cnt
					}
				}
			}
		}
		curPosMap = newPosMap
	}

	var totalPossibleCnt float64 = 0
	for _, cnt := range curPosMap {
		totalPossibleCnt += cnt
	}

	return float64(totalPossibleCnt) / (math.Pow(8, float64(k)))
}

func Test(t *testing.T) {
	{
		n, k, r, c := 3, 2, 0, 0
		exp := 0.0625
		res := knightProbability(n, k, r, c)
		if exp != res {
			t.Errorf("Expected: %v, Got: %v\n", exp, res)
		}
	}

	{
		n, k, r, c := 1, 0, 0, 0
		exp := 1.0
		res := knightProbability(n, k, r, c)
		if exp != res {
			t.Errorf("Expected: %v, Got: %v\n", exp, res)
		}
	}

	{
		n, k, r, c := 8, 30, 6, 4
		exp := 0.00019
		res := knightProbability(n, k, r, c)
		if exp != res {
			t.Errorf("Expected: %v, Got: %v\n", exp, res)
		}
	}

}

// this solution will encounter overflow when k is too large
func OVERFLOWknightProbability(n int, k int, row int, column int) float64 {
	curPosMap := make(map[pos]uint64)
	curPosMap[pos{row, column}] = 1

	for i := 0; i < k; i++ {
		newPosMap := make(map[pos]uint64)
		for pos, cnt := range curPosMap {
			newPosList := pos.possibleNextPos(n)
			for _, newPos := range newPosList {
				if _, ok := newPosMap[newPos]; !ok {
					newPosMap[newPos] = cnt
				} else {
					newPosMap[newPos] += cnt
				}
			}
		}
		curPosMap = newPosMap
	}

	var totalPossibleCnt uint64 = 0
	for _, cnt := range curPosMap {
		totalPossibleCnt += cnt
	}

	return float64(totalPossibleCnt) / (math.Pow(8, float64(k)))
}
