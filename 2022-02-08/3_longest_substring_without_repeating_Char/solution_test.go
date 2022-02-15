package longestSubstringWithoutRepeatingChar

import "testing"

func lengthOfLongestSubstring(s string) int {

	lastOccurAt := make(map[rune]int)
	from, maxLen := 0, 0
	for i, c := range s {
		if lastPos, ok := lastOccurAt[c]; ok && lastPos >= from {
			from = lastPos + 1
			lastOccurAt[c] = i
		} else {
			lastOccurAt[c] = i
		}

		curLen := i - from + 1
		if curLen > maxLen {
			maxLen = curLen
		}
	}

	return maxLen
}

func Test(t *testing.T) {
	if lengthOfLongestSubstring("abcabcbb") != 3 {
		t.Error()
	}
	if lengthOfLongestSubstring("bbbbb") != 1 {
		t.Error()
	}
	if lengthOfLongestSubstring("pwwkew") != 3 {
		t.Error()
	}
	if lengthOfLongestSubstring("abba") != 2 {
		t.Error()
	}
	if lengthOfLongestSubstring("aaaabbbba") != 2 {
		t.Error()
	}
	if lengthOfLongestSubstring("aaaabcbbba") != 3 {
		t.Error()
	}
	if lengthOfLongestSubstring("1111") != 1 {
		t.Error()
	}
	if lengthOfLongestSubstring("ab") != 2 {
		t.Error()
	}
}
