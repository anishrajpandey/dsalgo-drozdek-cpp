#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }
    int top = s.top();
    s.pop();
    insertAtBottom(s, val);
    s.push(top);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;

    int top = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, top);
}
