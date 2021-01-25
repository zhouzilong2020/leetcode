#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void reverseString(vector<char> &s)
  {
    int l = 0, r = s.size() - 1;
    char tem;
    while (l < r)
    {
      tem = s[l];
      s[l] = s[r];
      s[r] = tem;
      l++;
      r--;
    }

    
  }
};
