#include <vector>
#include <iostream>
using namespace std;

class Solution_75
{
public:
    void sortColorsSingleScan(vector<int> &nums)
    {
        vector<int>::iterator bg, ed;
        ed = nums.end();
        // curL/R表示目前扫描完成的部分，L/R表示已经排序完成的部分
        int curL = 0, curR = nums.size() - 1, L = -1, R = nums.size();
        int tem;
        while (curL < curR)
        {
            // 将两个数替换，确保大的一个在右边
            if (nums[curL] > nums[curR])
            {
                tem = nums[curL];
                nums[curL] = nums[curR];
                nums[curR] = tem;
            }

            // 如果右边的数字为2
            if (nums[curL] == 1 && nums[curR] == 1)
            {
                curL++;
                curR--;
            }
            if (nums[curR] == 2)
            {
                R--;
                nums[curR] = nums[R];
                nums[R] = 2;
                curR--;
            }
            if (nums[curL] == 0)
            {
                L++;
                nums[curL] = nums[L];
                nums[L] = 0;
                curL++;
            }
        }
        // 最后二者刚好相等，需要进一步判断
        if (curL == curR)
        {
            if (nums[curL] == 0)
            {
                L++;
                nums[curL] = nums[L];
                nums[L] = 0;
            }
            else if (nums[curR] == 2)
            {
                R++;
                nums[curR] = nums[R];
                nums[R] = 2;
            }
        }
    };
    void sortColors(vector<int> &nums)
    {
        vector<int>::iterator bg, ed;
        ed = nums.end();
        int cnt_0 = 0, cnt_1 = 0;
        for (bg = nums.begin(); bg != ed; bg++)
        {
            switch (*bg)
            {
            case 0:
                cnt_0++;
                break;
            case 1:
                cnt_1++;
                break;
            }
        }
        for (bg = nums.begin(); bg != ed; bg++)
        {
            if (cnt_0 != 0)
            {
                *bg = 0;
                cnt_0--;
            }
            else if (cnt_1 != 0)
            {
                *bg = 1;
                cnt_1--;
            }
            else
            {
                *bg = 2;
            }
        }
    }
};

int main(int argc, const char *argv[])
{

    vector<int> nums;
    int a[] = {0, 2, 2, 2, 0, 2, 1, 1};
    for (int i = 0; i < 8; i++)
    {
        nums.push_back(a[i]);
    }
    Solution_75 solution_75;
    solution_75.sortColorsSingleScan(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
