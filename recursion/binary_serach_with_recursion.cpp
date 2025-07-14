#include <iostream>
using namespace std;

int binary_search(int arr[], int target, int left, int right)
{
    if (left > right)
        return -1; // base case: target not found
    int mid = (left + right) / 2;
    if (target > arr[mid])
    {
        left = mid + 1;
        return binary_search(arr, target, left, right);
    }
    else if (target < arr[mid])
    {
        right = mid - 1;
        return binary_search(arr, target, left, right);
    }
    else
        return mid;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    cout << binary_search(arr, 7, 0, 6);
}