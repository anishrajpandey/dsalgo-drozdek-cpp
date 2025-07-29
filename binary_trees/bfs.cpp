#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

void TraverseBFS(TreeNode *root)

{
    queue<TreeNode *> q;
    if (root == nullptr)
        return;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        cout << root->val;
        q.pop();
        if (root->left != nullptr)
            q.push(root->left);
        if (root->right != nullptr)
            q.push(root->right);
    }

    return;
}
