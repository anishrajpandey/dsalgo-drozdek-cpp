#include <iostream>
#include <vector>
using namespace std;

void getAllSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
{
    if (i == nums.size())
    {
        allSubsets.push_back(ans);
        return;
    }
    // include
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allSubsets);

    ans.pop_back();
    // exclude
    getAllSubsets(nums, ans, i + 1, allSubsets);
}

int main()
{
    vector<int> nums = {1, 2, 3}; // Example input
    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allSubsets);

    // Print all subsets
    for (const auto &subset : allSubsets)
    {
        cout << "{ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}