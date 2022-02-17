package longestpalindromicsubstring

import "testing"

func longestPalindrome(s string) string {
	sLen := len(s)
	if sLen == 1 { // special case
		return s
	}

	dp := make([][]int, sLen)
	for i := 0; i < sLen; i++ {
		dp[i] = make([]int, sLen)
		dp[i][i] = 1
	}

	for i := 0; i < sLen; i++ {
		for j := 0; j < i; j++ {
			// asd
		}
	}

	//  a b a c a b a d e f
	//  1 1
	return "asd"
}

func Test(t *testing.T) {
	longestPalindrome("Asdasd")
}
