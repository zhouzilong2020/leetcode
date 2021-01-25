//
//  main.cpp
//  75 颜色排序
//
//  Created by  周子龙 on 2020/10/7.
//  Copyright © 2020  周子龙. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution_75 {
public:
    void sortColors(vector<int>& nums) {
        vector<int>::iterator bg, ed;
        ed = nums.end();
        int cnt_0 = 0, cnt_1 = 0;
        for( bg = nums.begin(); bg != ed; bg++){
            switch (*bg) {
                case 0:
                    cnt_0++;
                    break;
                case 1:
                    cnt_1++;
                    break;
            }
        }
        for( bg = nums.begin(); bg != ed; bg++){
            if( cnt_0 != 0 ){
                *bg = 0;
                cnt_0--;
            }else if( cnt_1 != 0 ){
                *bg = 1;
                cnt_1--;
            }else{
                *bg = 2;
            }
        }
    }
    void sortColors_singleScan(vector<int> &nums){
        vector<int>::
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    nums = {2,0,2,1,1,0};
    Solution_75 solution_75;
    solution_75.sortColors(nums);
    for(int i = 0; i < nums.size(); i++){
        printf("%d ", nums[i]);
    }
    
    return 0;
}
