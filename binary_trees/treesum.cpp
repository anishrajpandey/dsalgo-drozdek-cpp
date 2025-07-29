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

int TraverseDFS(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    cout << root->val;
    int leftSum = TraverseDFS(root->left);
    int rightSum = TraverseDFS(root->right);

    return leftSum + rightSum + root->val;
}
