#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    // 空返回没有, 或者刚好是一个自环
    if (head == NULL)
    {
      return false;
    }
    ListNode *p1 = head, *p2 = head;
    while (p2)
    {
      p2 = p2->next;
      p1->next = p1;
      // 判断是否形成了环
      if (p1 == p2)
      {
        return true;
      }

      p1 = p2;
    }
    return false;
  }
};