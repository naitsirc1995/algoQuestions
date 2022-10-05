package main

func BinarySearch(array []int, target int) int {

	bottom := 0
	top := len(array) - 1
	var mIdx int
	for bottom <= top {
		mIdx = (top + bottom) / 2
		if array[mIdx] < target {
			bottom = mIdx + 1
		} else if array[mIdx] > target {
			top = mIdx - 1
		}

		if array[mIdx] == target {
			return mIdx
		}
	}
	return -1
}
