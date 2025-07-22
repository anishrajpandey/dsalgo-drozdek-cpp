#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permute(vector<int> &nums, int index = 0, vector<vector<int>> &permutations)
{

    if (index == nums.size())
    {
        permutations.push_back({nums});
        return permutations;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        permute(nums, index + 1, permutations);
        swap(nums[index], nums[i]);
    }
    return permutations;
}
