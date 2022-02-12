#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int DIR[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int height;
    int length;
    void tryTurnoverLand(int x, int y, vector<vector<int>> &grid)
    {
        if ((x < 0 || x >= height) ||
            (y < 0 || y >= length) ||
            grid[x][y] == 0)
        {
            return;
        }

        grid[x][y] = 0;
        for (auto dir : DIR)
        {
            int newX = x + dir[0];
            int newY = y + dir[1];

            tryTurnoverLand(newX, newY, grid);
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        height = grid.size();
        length = grid[0].size();

        for (int i = 0; i < height; i++)
        {
            if (grid[i][0] == 1)
            {
                tryTurnoverLand(i, 0, grid);
            }
            if (grid[i][length - 1] == 1)
            {
                tryTurnoverLand(i, length - 1, grid);
            }
        }

        for (int i = 0; i < length; i++)
        {
            if (grid[0][i] == 1)
            {
                tryTurnoverLand(0, i, grid);
            }
            if (grid[height - 1][i] == 1)
            {
                tryTurnoverLand(height - 1, i, grid);
            }
        }

        int cnt = 0;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < length; j++)
            {
                if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main()
{
    Solution s;

    // the iterator constructor can also be used to construct from arrays:
    int rawGrid1[4][4] = {{0, 0, 0, 0},
                          {1, 0, 1, 0},
                          {0, 1, 1, 0},
                          {0, 0, 0, 0}};

    // [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
    int rawGrid[4][4] = {{0, 1, 1, 0},
                         {0, 0, 0, 0},
                         {0, 1, 1, 0},
                         {0, 0, 0, 1}};

    vector<vector<int>> grid;
    for (int i = 0; i < 4; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 4; j++)
        {
            temp.push_back(rawGrid[i][j]);
        }

        grid.push_back(temp);
    }

    cout << s.numEnclaves(grid);
}