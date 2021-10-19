#include <bits/stdc++.h>
using namespace std;

// print distinct elements in each window of size k
void printDistinct(int arr[], int n, int k)
{
    // initialize map
    map<int, int> counter;

    // count upto k
    for (int i = 0; i < k; i++)
        counter[arr[i]]++;

    // print size upto k
    cout << counter.size() << " ";

    // for subsequenct window
    for (int i = k; i < n; i++)
    {
        // add current element
        counter[arr[i]]++;

        // remove previous element
        counter[arr[i - k]]--;

        // if previous element is completely removed erase
        if (counter[arr[i - k]] == 0)
            counter.erase(arr[i - k]);

        // print current map size
        cout << counter.size() << " ";
    }
}

// Driver dcode
int main()
{
    // Given array
    int arr[] = {10, 20, 20, 10, 30, 40, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    // fn call
    printDistinct(arr, n, k);
}