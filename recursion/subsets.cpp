#include <iostream>
#include <vector>
using namespace std;

void printSubsets(const vector<int> &arr, int index, vector<int> &subsets)
{
    if (index == arr.size())
    {

        for (int i = 0; i < subsets.size(); i++)
        {
            cout << subsets[i];
        }
        cout << endl;
        return;
    }

    subsets.push_back(arr[index]);
    printSubsets(arr, index + 1, subsets);

    printSubsets(arr, index + 1, subsets);
    subsets.pop_back();
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> subsets;
    printSubsets(arr, 0, subsets);
    return 0;
}