#include <iostream>
#include <math.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

int TraverseDFS(TreeNode *root)
{
    if (root == nullptr)
        return INFINITY;

    int left = TraverseDFS(root->left);
    int right = TraverseDFS(root->right);

    return left < right ? left : right;
}
