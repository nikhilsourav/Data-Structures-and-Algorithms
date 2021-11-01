/*
    Sort an array by frequence of each element (higher freq element first)
    eg: [1,2,2,3,3,3,4,4,4,4] => [4,4,4,4,3,3,3,2,2,1]
*/

#include <bits/stdc++.h>
using namespace std;

// Sort array by frequency
vector<int> sortByFreq(int arr[], int n)
{
    // create map
    unordered_map<int, int> freq;

    // store frequency
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // vect of pair
    vector<pair<int, int>> vectPair;

    // store map elements in vector
    for (auto &val : freq)
        vectPair.push_back(val);

    // sort
    sort(begin(vectPair), end(vectPair), [&](pair<int, int> a, pair<int, int> b)
         { return a.second != b.second ? a.second > b.second : a.first < b.first; });

    // export answer
    vector<int> result;
    for (auto &val : vectPair)
        while (val.second--)
            result.push_back(val.first);

    // return
    return result;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Output
    vector<int> ans = sortByFreq(arr, n);
    for (auto x : ans)
        cout << x << " ";
}