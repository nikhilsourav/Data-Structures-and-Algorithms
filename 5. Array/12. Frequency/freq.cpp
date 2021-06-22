#include <bits/stdc++.h>
using namespace std;

// count frequency in sorted array
void printFrequency(int *arr, int size)
{
    // init var:
    int freq = 1;

    // logic:
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == arr[i + 1])
            freq++;
        else
        {
            cout << "frequency of " << arr[i] << " is: " << freq << "\n";
            freq = 1;
        }
    }
}

// Driver code
int main()
{
    // Given arrary
    int arr[] = {10, 10, 10, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    // display frequency
    printFrequency(arr, size);
}