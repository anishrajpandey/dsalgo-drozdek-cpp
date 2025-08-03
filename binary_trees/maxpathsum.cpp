#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    };
};

TreeNode *generateTree(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inStart, int inEnd, unordered_map<int, int> &inMap)
{
    if (preIndex >= preorder.size() || inStart > inEnd)
        return nullptr;

    int rootVal = preorder[preIndex++];
    TreeNode *root = new TreeNode(rootVal);

    int inIndex = inMap[rootVal];

    root->left = generateTree(preorder, inorder, preIndex, inStart, inIndex - 1, inMap);
    root->right = generateTree(preorder, inorder, preIndex, inIndex + 1, inEnd, inMap);

    return root;
}

TreeNode *build(vector<int> &preorder, vector<int> &inorder)
{
    int preIndex = 0;
    int inStart = 0;
    int inEnd = inorder.size() - 1;

    unordered_map<int, int> inMap;
    for (int i = 0; i <= inEnd; i++)
    {
        inMap[inorder[i]] = i;
    }

    return generateTree(preorder, inorder, preIndex, inStart, inEnd, inMap);
}

void printTree(TreeNode *root)
{
    if (!root)
        return;

    cout << root->val;

    if (root->left || root->right)
    {
        cout << "(";
        if (root->left)
            printTree(root->left);
        cout << ",";
        if (root->right)
            printTree(root->right);
        cout << ")";
    }
}

int maxPathSum(TreeNode *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->val;
    }

    if (root == nullptr)
    {
        return -INFINITY;
    }
    int leftmax = maxPathSum(root->left);
    int rightmax = maxPathSum(root->right);
    int maximum = max(leftmax, rightmax);
    return root->val + maximum;
}
int main()
{
    vector<int> preorder;
    preorder.push_back(23);
    preorder.push_back(24);
    preorder.push_back(2);
    preorder.push_back(9);
    preorder.push_back(87);
    preorder.push_back(1);
    preorder.push_back(50);
    preorder.push_back(3);
    preorder.push_back(30);
    preorder.push_back(12);

    vector<int> inorder;
    inorder.push_back(2);
    inorder.push_back(24);
    inorder.push_back(9);
    inorder.push_back(87);
    inorder.push_back(23);
    inorder.push_back(3);
    inorder.push_back(50);
    inorder.push_back(1);
    inorder.push_back(30);
    inorder.push_back(12);

    TreeNode *TreeRoot = build(preorder, inorder);
    cout << maxPathSum(TreeRoot);
}