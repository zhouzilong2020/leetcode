//
// Created by zhouzilong on 2022/2/8.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    unordered_map<int, int> rows;
    unordered_map<int, int> cols;
    unordered_map<int, int> positiveK;
    unordered_map<int, int> negativeK;
    set<vector<int>> lampSet;

public:
    inline bool isInline(const int &x, const int &y)
    {
        if (rows[x] > 0 || cols[y] > 0 || positiveK[y - x] > 0 || negativeK[x + y] > 0)
        {
            return true;
        }
        return false;
    }

    inline void turnOffLight(const int &x, const int &y)
    {
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                const int newX = x + i, newY = y + j;
                if (lampSet.find(vector<int>{newX, newY}) != lampSet.end())
                {
                    rows[newX]--;
                    cols[newY]--;
                    positiveK[newY - newX]--;
                    negativeK[newX + newY]--;
                    lampSet.erase(vector<int>{newX, newY});
                }
            }
        }
    }

    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        for (vector<int> lampPos : lamps)
        {
            lampSet.insert(lampPos);
        }

        for (vector<int> lampPos : lampSet)
        {
            const int x = lampPos[0], y = lampPos[1];
            rows[x]++;
            cols[y]++;
            positiveK[y - x]++;
            negativeK[x + y]++;
        }

        vector<int> result;
        for (int i = 0, len = queries.size(); i < len; i++)
        {
            const int x = queries[i][0], y = queries[i][1];
            if (!isInline(x, y))
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(1);
            }

            turnOffLight(x, y);
        }
        return result;
    }
};

int main()
{
    Solution s;
    int n = 6;
    vector<vector<int>> lamps, queries;

    lamps.push_back(vector<int>{1, 1});
    // lamps.push_back(vector<int>{1, 0});
    queries.push_back(vector<int>{2, 0});
    queries.push_back(vector<int>{1, 0});

    vector<int> res = s.gridIllumination(n, lamps, queries);
    for (auto i : res)
    {
        cout << i << endl;
    }
}