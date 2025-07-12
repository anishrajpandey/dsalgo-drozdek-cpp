#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    ListNode *copyRandomList(ListNode *head)
    {
        unordered_map<ListNode *, ListNode *> oldToNew;
        ListNode *p = head;
        while (p != nullptr)
        {
            oldToNew[p] = new ListNode(p->val);
            p = p->next;
        }
        p = head;
        while (p != nullptr)
        {
            oldToNew[p]->next = oldToNew[p->next];
            oldToNew[p]->random = oldToNew[p->random];
            p = p->next;
        }

        return oldToNew[head];
    };
};