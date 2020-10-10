//
//  main.c
//  BinarySearch
//
//  Created by  周子龙 on 2019/1/19.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int search(int* nums, int numsSize, int target);
    int nums[] = {-1};
    int target = -1;
    int numsSize =1;
    int index = search(nums, numsSize, target);
    printf("%d" , index);
    return 0;
}

int search(int* nums, int numsSize, int target) {
    int binarySearch(int left, int rignt, int target, int* nums);
    int index = binarySearch(0, numsSize-1, target, nums);
    return index;
}

int binarySearch(int left, int right, int target, int* nums){
    int mid = (left+right)/2;
    int index = -1;
    
     if(nums[mid] == target)
         return mid;
    if(nums[mid+1] == target && mid+1 <= right)
        return mid+1;
    if(nums[mid] > target && right - left > 1)
        index = binarySearch( left, mid-1, target, nums);
    if(nums[mid] < target && right - left > 1)
        index = binarySearch( mid+1, right, target, nums);
    
    return index;
}
