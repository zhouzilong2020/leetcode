#include <iostream>

using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode();
        ListNode *curHead = result;
        int tempSum = 0, d1 = 0, d2 = 0;
        while (l1 != nullptr || l2 != nullptr || d2 != 0)
        {
            tempSum = d2;
            if (l1 != nullptr)
            {
                tempSum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                tempSum += l2->val;
                l2 = l2->next;
            }

            // tempSum = d2 * 10 + d1
            d1 = tempSum % 10;
            d2 = tempSum / 10;

            curHead->next = new ListNode(d1);
            curHead = curHead->next;
        }

        return result->next;
    }
};

int main()
{
    Solution s;

    ListNode *l1, *l2;
    l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    s.addTwoNumbers(l1, l2);
}