#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getArea(const int &l, const int &r, const int &dis) {
        int lower = l > r ? r : l;
        return dis * lower;
    }

    int maxArea_violent(vector<int> &height) {
        int max = 0;
        int area;
        for (int i = 0, len = height.size(); i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                area = getArea(height[i], height[j], j - i);
                max = max > area ? max : area;
            }
        }
        return max;
    }


};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> a{1, 1};
    cout << s.maxArea(a);
    return 0;
}
