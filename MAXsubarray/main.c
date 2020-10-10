//
//  main.c
//  MAXsubarray
//
//  Created by  周子龙 on 2019/1/19.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>

int main(){
    int maxSubArray(int* nums, int numsSize);
    int arr[] = {8,-19,5,-4,20};
    int sizearr = 5;
    int max = maxSubArray(arr, sizearr);
    printf("%d", max);
}

int maxSubArray(int* nums, int numsSize) {
    int fenzhi(int left, int rignt, int* nums);
    int max;
    max = fenzhi(0, numsSize-1, nums);
    return max;
}

int fenzhi(int left, int right, int* nums){
    if(right - left > 1)
    {
        int mid = 0;
        int val_lef = 0, val_rig = 0;
        int max = 0;
        mid = (right+left)/2;
        
        val_lef = fenzhi(left, mid, nums);
        val_rig = fenzhi(mid+1, right, nums);
        
        if(val_lef > val_rig)
            max = val_lef;
        else max = val_rig;
        
        int max_cross = 0;
        int max_sum_lef = nums[mid], max_sum_rig = nums[mid+1];
        int tem = 0;
        for(int i = mid; i >= left; i--){
            tem += nums[i];
            if(max_sum_lef < tem)
                max_sum_lef = tem;
        }
        tem = 0;
        for(int i = mid+1; i <= right; i++){
            tem += nums[i];
            if(max_sum_rig < tem)
                max_sum_rig = tem;
        }
        max_cross = max_sum_rig + max_sum_lef;
        if(max_cross > max)
            max = max_cross;
        return max;
    }
    
    else
    {
        int max = 0;
        if(nums[left] > nums[right])
            max = nums[left];
        else
            max = nums[right];
        if(nums[left]+nums[right] > max && left != right)
            max = nums[left]+nums[right];
        return max;
    }
    
    return 0;
}

