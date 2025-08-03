#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &arr, int start, int end)
{

    // if (start == end)

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
}

void main()
{
}