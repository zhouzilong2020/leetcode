#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        vector<int> res;
        for (int &i : nums)
        {
            m[i]++;
        }

        int first, second;
        bool found = false;
        for (auto &num : m)
        {
            int r = target - num.first;
            if (m[r] > 0)
            {
                first = num.first;
                if (r == num.first && num.second > 1)
                {
                    second = num.first;
                    found = true;
                    break;
                }
                else if (r != num.first)
                {
                    second = r;
                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            return res;
        }

        for (int i = 0, len = nums.size(); i < len; i++)
        {
            if (nums[i] == first || nums[i] == second)
            {
                res.emplace_back(i);
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> sums = {0, 4, 3, 0};
    vector<int> a = s.twoSum(sums, 0);
    for (auto &i : a)
    {
        cout << i;
    }
}