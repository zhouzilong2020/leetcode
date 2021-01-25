#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    if (head == NULL)
    {
      return NULL;
    }
    ListNode *p1 = head, *p2 = head, *last = NULL, *pos = NULL;
    int cnt = 0;
    vector<ListNode *> history;
    while (p2)
    {
      history.push_back(p2->next);
      p2 = p2->next;
      p1->next = last;
      last = p1;
      p1 = p2;
    }
    p2 = head;

    // 如果最后一个修改的是头节点, 说明存在一个环
    if (last == head)
    {
      int len = history.size();
      while (cnt < len)
      {
        if (p2->next == history[cnt])
        {
          p2 = p2->next;
          cnt++;
        }
        else
        {
          pos = p2;
          while (cnt < len)
          {
            p2->next = history[cnt];
            cnt++;
          }
        }
      }
    }
    else
    {
      for (int i = 0, len = history.size(); i < len; i++)
      {
        p2->next = history[i];
        p2 = history[i];
      }
    }
    return pos;
  }
};