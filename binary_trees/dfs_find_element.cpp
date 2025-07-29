#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

bool TraverseDFS(TreeNode *root, int value)
{
    if (root == nullptr)
        return false;
    if (root->val == value)
        return true;
    bool left = TraverseDFS(root->left, value);
    bool right = TraverseDFS(root->right, value);
    return left || right;
}
