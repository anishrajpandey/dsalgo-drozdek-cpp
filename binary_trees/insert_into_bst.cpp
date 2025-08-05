#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *insert(int val, TreeNode *root)

{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }
    if (val < root->val)
        root->left = insert(val, root->left);
    else
        root->right = insert(val, root->right);

    return root;
}