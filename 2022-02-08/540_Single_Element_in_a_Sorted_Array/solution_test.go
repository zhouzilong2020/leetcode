package singleelementinasortedarray_test

import (
	"testing"
)

// 0 0 1 1 3
func singleNonDuplicate(nums []int) int {
	len := len(nums)
	l, r := 0, len-1
	for {

		mid := (l + r) / 2
		mid += mid % 2
		if mid+1 < len && nums[mid] == nums[mid+1] {
			l = mid + 2
		} else if -1 < (mid-1) && nums[mid-1] == nums[mid] {
			r = mid - 2
		} else {
			return nums[mid]
		}
	}
}

func Test(t *testing.T) {
	if aws := singleNonDuplicate([]int{1, 1, 2, 3, 3}); aws != 2 {
		t.Errorf("expected: 2, got: %d", aws)
	}

	if aws := singleNonDuplicate([]int{1, 1, 2, 2, 3}); aws != 3 {
		t.Errorf("expected: 3, got: %d", aws)
	}

	if aws := singleNonDuplicate([]int{0, 1, 1, 2, 2}); aws != 0 {
		t.Errorf("expected: 0, got: %d", aws)
	}

	if aws := singleNonDuplicate([]int{1, 1, 2, 2, 3, 4, 4}); aws != 3 {
		t.Errorf("expected: 3, got: %d", aws)
	}

	if aws := singleNonDuplicate([]int{0, 0, 1, 2, 2, 3, 3}); aws != 1 {
		t.Errorf("expected: 0, got: %d", aws)
	}

	if aws := singleNonDuplicate([]int{1, 1, 2, 3, 3, 4, 4, 8, 8}); aws != 2 {
		t.Errorf("expected: 2, got: %d", aws)
	}

	if aws := singleNonDuplicate([]int{3, 3, 7, 7, 10, 11, 11}); aws != 10 {
		t.Errorf("expected: 10, got: %d", aws)
	}

	if aws := singleNonDuplicate([]int{3}); aws != 3 {
		t.Errorf("expected: 3, got: %d", aws)
	}

}
