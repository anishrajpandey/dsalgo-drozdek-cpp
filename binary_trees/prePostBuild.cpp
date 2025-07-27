#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

TreeNode *buildFromPrePost(vector<int> &preorder, vector<int> &postorder, int &preIndex, int &postIndex)
{
    TreeNode *root = new TreeNode(preorder[preIndex++]);

    if (root->val != postorder[postIndex])
    {
        root->left = buildFromPrePost(preorder, postorder, preIndex, postIndex);
    }
    if (root->val != postorder[postIndex])
    {
        root->right = buildFromPrePost(preorder, postorder, preIndex, postIndex);
    }

    postIndex++;
    return root;
}

TreeNode *build(vector<int> &preorder, vector<int> &postorder)
{
    int preIndex = 0, postIndex = 0;
    return buildFromPrePost(preorder, postorder, preIndex, postIndex);
}

// Helper to test result
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    vector<int> preorder;
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(4);
    preorder.push_back(5);
    preorder.push_back(3);
    preorder.push_back(6);
    preorder.push_back(7);

    vector<int> postorder;
    postorder.push_back(4);
    postorder.push_back(5);
    postorder.push_back(2);
    postorder.push_back(6);
    postorder.push_back(7);
    postorder.push_back(3);
    postorder.push_back(1);

    TreeNode *root = build(preorder, postorder);
    inorder(root); // Should print the tree in inorder traversal
    return 0;
}
