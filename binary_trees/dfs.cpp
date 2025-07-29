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

void TraverseDFS(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->val;
    TreeNode *left = root->left;
    TreeNode *right = root->right;

    return;
}
