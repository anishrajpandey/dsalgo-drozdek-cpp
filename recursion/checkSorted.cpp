#include <iostream>
#include <vector>
using namespace std;
bool isSorted(const vector<int> &arr, int index = 0)
{
    if (index == arr.size() - 1)
    {
        return true;
    };

    if (arr[index] > arr[index + 1])
        return false;
    return isSorted(arr, index + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    if (isSorted(arr))
    {
        cout << "Array is sorted.\n";
    }
    else
    {
        cout << "Array is not sorted.\n";
    }
    return 0;
}