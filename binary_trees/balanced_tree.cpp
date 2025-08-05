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

struct response
{
    int height;
    bool isBalanced;
};

response isTreeBalanced(TreeNode *root, int h)
{

    if (root == nullptr)
    {
        response rs={
            height:0;
            isBalanced:false;
        }
    }
        return 

    isTreeBalanced(root->left, h + 1);
    isTreeBalanced(root->right, h + 1);
}

int main()
{
}