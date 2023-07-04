// To get peak of a mountain array using binary search.

#include <iostream>
using namespace std;

int mountainPeak(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] < arr[mid + 1])
            start = mid + 1;

        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return arr[start];
}

int main()
{
    int arr[12] = {1, 2, 3, 5, 6, 7, 8, 66, 54, 4, 2, 1};
    cout << mountainPeak(arr, 12) << endl;
    return 0;
}