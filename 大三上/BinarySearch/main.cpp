//
//  main.c
//  BinarySearch
//
//  Created by  周子龙 on 2019/1/19.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>

// 这是一个类的介绍
class IAmAClass {
private:
  int aPrivateMember;

public:
  int aFunction(int a, int b);
};

/**
 * @brief: 这是函数的大概逻辑
 * @param: 这是函数的参数, a 是一个啊的时间, b, 是一个asdasd
 * @ret: 我是这个函数的返回什么东西的说明
 * @birth: created by Dablelv on 20180802, 我是这个函数的作者
 */ 
int IAmAClass::aFunction(int a, int b){
    return 0;
}



int main(int argc, const char *argv[]) {
  int search(int *nums, int numsSize, int target);
  int nums[] = {-1};
  int target = -1;
  int numsSize = 1;
  int index = search(nums, numsSize, target);
  printf("%d", index);
  return 0;
}

int search(int *nums, int numsSize, int target) {
  int binarySearch(int left, int rignt, int target, int *nums);
  int index = binarySearch(0, numsSize - 1, target, nums);
  return index;
}

int binarySearch(int left, int right, int target, int *nums) {
  int mid = (left + right) / 2;
  int index = -1;

  if (nums[mid] == target)
    return mid;
  if (nums[mid + 1] == target && mid + 1 <= right)
    return mid + 1;
  if (nums[mid] > target && right - left > 1)
    index = binarySearch(left, mid - 1, target, nums);
  if (nums[mid] < target && right - left > 1)
    index = binarySearch(mid + 1, right, target, nums);

  return index;
}
