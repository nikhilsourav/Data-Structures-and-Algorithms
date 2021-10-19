#include <bits/stdc++.h>
using namespace std;

// Find pair with given sum in unsorted array
pair<int, int> pairWithSumX(int arr[], int n, int sum)
{
    // init set
    unordered_set<int> sumFinder(arr, arr + n);

    // logic:
    for (auto val : sumFinder)
        if (sumFinder.find(sum - val) != sumFinder.end())
            return make_pair(*sumFinder.find(sum - val), val);

    // otherwise
    return make_pair(-1, -1);
}

// Driver code
int main()
{
    // Given array
    int arr[] = {3, 8, 4, 7, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Given sum
    int sum = 9;

    // fn call
    pair<int, int> sumPair = pairWithSumX(arr, n, sum);
    cout << sumPair.first << " " << sumPair.second;
}