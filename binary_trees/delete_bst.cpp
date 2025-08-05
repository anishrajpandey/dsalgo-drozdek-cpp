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

TreeNode *deleteNode(TreeNode *root, int val)
{
    if (root == nullptr)
        delete root;

    if (root->val > val)
    {
        TreeNode *left = deleteNode(root->left, val);
    }
    else
        TreeNode *right = deleteNode(root->right, val);

    return root;
}