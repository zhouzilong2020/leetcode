#include <unordered_set>
#include <iostream>

#include <set>
#include <vector>
using namespace std;

// TODO: some corner cases still need to be considered
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int p = 0, n = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (nums[i] >= 0)
            {
                p++;
            }
            if (nums[i] <= 0)
            {
                n++;
            }
        }

        int temp = p;
        p = n;                      // the starting position of positive number
        n = nums.size() - temp - 1; // the ending position of negative number

        vector<vector<int>> res;
        if (p - n - 1 >= 3)
        {
            res.push_back(vector<int>{0, 0, 0});
            cout << 000000000 << endl;
        }

        unordered_set<int> s;
        if (p - n > 1)
        {
            s.insert(0);
        }

        int requiredNum;
        while (p < len && n >= 0)
        {

            requiredNum = 0 - nums[p] - nums[n];

            if (s.find(requiredNum) != s.end())
            {
                if (res.size() != 0 && res[res.size() - 1][0] == nums[p] && res[res.size() - 1][1] == nums[n]) // duplicate
                {
                    break;
                }

                vector<int> r;
                r.push_back(nums[p]);
                r.push_back(nums[n]);
                r.push_back(requiredNum);
                cout << nums[p] << " " << nums[n] << " " << requiredNum << endl;
                res.push_back(r);
            }

            if (requiredNum == 0)
            {
                s.insert(nums[p++]);
                s.insert(nums[n--]);
            }
            else if (requiredNum < 0)
            {
                s.insert(nums[n--]);
            }
            else
            {
                s.insert(nums[p++]);
            }
        }

        return res;
    }
};

int main()
{
    Solution s;

    // vector<int> nums1{1, 0, -1};
    // vector<int> nums2{0, 0};
    // vector<int> nums3{0, 0, 0};
    // vector<int> nums4{1, 0, -1};
    vector<int> nums5{3, 0, -2, -1, 1, 2};

    // s.threeSum(nums1);
    // s.threeSum(nums2);
    // s.threeSum(nums3);
    // s.threeSum(nums4);
    s.threeSum(nums5);
    // s.threeSum(nums6);
}