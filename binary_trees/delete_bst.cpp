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
    if (root->left == nullptr && root->right == nullptr)
    {
        if (root->val == val)
        {
            delete root;
        }
        return;
    }

    if (root->left == nullptr && root->right != nullptr)
    {
        if (root->right->val == val)
        {
            // root->right = root->right->;
        }
        return;
    }

    if (root->val > val)
    {
        root->left = deleteNode(root->left, val);
    }
    else if ((root->val < val))
        root->right = deleteNode(root->right, val);
    else
    {
    }
    return root;
}