#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> res;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++){
                if(__gcd(i,j) == 1){
                    res.emplace_back(to_string(j)+"/"+to_string(i));
                }

            }
            
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> res = s.simplifiedFractions(10);
    for (auto i : res)
    {
        cout << i << endl;
    }
}