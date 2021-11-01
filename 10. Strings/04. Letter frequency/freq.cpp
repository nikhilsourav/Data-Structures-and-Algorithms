/*
    Given a string of lowercase chars. Print sorted chars and their freq
    
    Dry Run:
    * freq[26] = {0,0,0 ... 0}
    * Iteration 1: 'g' - 'a' = 7  (value at index 6 = 1)
    * Iteration 2: 'e' - 'a' = 5  (value at index 4 = 1)
    * Iteration 3: 'e' - 'a' = 5  (value at index 4 = 2)
    * Iteration 4: 'k' - 'a' = 11 (value at index 10 = 1)
    * Iteration 5: 's' - 'a' = 19 (value at index 18 = 1)
    * Traverse array upto index 4 (print 4 + 'a' = 'e' and value = 2)
    * Traverse array upto index 6 (print 6 + 'a' = 'g' and value = 1)
    * Traverse array upto index 10 (print 10 + 'a' = 'k' and value = 1)
    * Traverse array upto index 18 (print 18 + 'a' = 's' and value = 1)
*/

#include <bits/stdc++.h>
using namespace std;

// Utility fn
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << "Index: " << i << " Value: " << arr[i] << "\n";
}

// Driver code
int main()
{
    // Given string
    string str = "geeks";

    // Init freq array with 0
    int size = 26;
    int freq[size] = {};

    // Store occurance and each char as index
    for (int i = 0; i < str.size(); i++)
        freq[str[i] - 'a']++;

    // Check freq array at this point
    print(freq, size);

    // Output char and its freq
    for (int i = 0; i < 26; i++)
        if (freq[i])
            cout << (char)(i + 'a') << " " << freq[i] << "\n";
}