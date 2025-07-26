#include <iostream>
#include <vector>
using namespace std;

// preorder: root left right

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
    }
};

TreeNode *createTree(vector<int> arr, int index)
{
    index++;
    if (index == arr.size())
        return nullptr;

    // for(int i=0;i<arr.size();i++){
    TreeNode *root = new TreeNode(arr[index]);
    root->left = createTree(arr, index);

    root->right = createTree(arr, index);

    return root;

    // }
}

int main()
{
    vector<int> arr;
    arr = {3, 9, 20, 15, 7};
    createTree(arr, 0);
    return 0;
}
// j