package maximumnumberofballoons

func maxNumberOfBalloons(text string) int {
	dic := map[rune]int{'b': 0, 'a': 0, 'l': 0, 'o': 0, 'n': 0}

	for _, c := range text {
		if _, ok := dic[c]; ok {
			dic[c]++
			if c == 'b' || c == 'a' || c == 'n' {
				dic[c]++
			}
		}
	}
	min := 10000
	for _, val := range dic {
		if val < min {
			min = val
		}
	}

	return min / 2
}
