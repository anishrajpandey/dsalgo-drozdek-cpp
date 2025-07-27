#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildFromPreIn(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inStart, int inEnd, unordered_map<int, int> &inMap)
{
    if (inStart > inEnd)
        return nullptr;

    int rootVal = preorder[preIndex++];
    TreeNode *root = new TreeNode(rootVal);
    int inIndex = inMap[rootVal];

    root->left = buildFromPreIn(preorder, inorder, preIndex, inStart, inIndex - 1, inMap);
    root->right = buildFromPreIn(preorder, inorder, preIndex, inIndex + 1, inEnd, inMap);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }
    int preIndex = 0;
    return buildFromPreIn(preorder, inorder, preIndex, 0, inorder.size() - 1, inMap);
}

// Optional: Inorder print to verify
void printPreorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    vector<int> preorder;
    preorder.push_back(3);
    preorder.push_back(9);
    preorder.push_back(20);
    preorder.push_back(15);
    preorder.push_back(7);

    vector<int> inorder;
    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);

    TreeNode *root = buildTree(preorder, inorder);

    cout << "Inorder of constructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
