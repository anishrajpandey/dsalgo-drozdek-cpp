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

TreeNode *buildWithInPost(vector<int> &inorder, vector<int> &postorder, int &postIndex, int inStart, int inEnd, unordered_map<int, int> &inMap)
{
    if (inStart > inEnd)
        return nullptr;

    int val = postorder[postIndex--];
    TreeNode *root = new TreeNode(val);
    int inIndex = inMap[val];

    // Build right subtree first
    root->right = buildWithInPost(inorder, postorder, postIndex, inIndex + 1, inEnd, inMap);
    root->left = buildWithInPost(inorder, postorder, postIndex, inStart, inIndex - 1, inMap);

    return root;
}

TreeNode *build(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    int postIndex = postorder.size() - 1;
    return buildWithInPost(inorder, postorder, postIndex, 0, inorder.size() - 1, inMap);
}

// Optional: helper to test your tree
void preorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode *root = build(inorder, postorder);
    preorder(root); // Expected: 3 9 20 15 7
    return 0;
}
