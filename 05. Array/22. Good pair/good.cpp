/*
    Given an numsay of integers nums.
    A pair (i,j) is called good if nums[i] == nums[j] and i < j.
    Return the number of good pairs.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Count how many times each number appears. 
    If a number appears n times, then n * (n – 1) // 2 
    good pairs can be made with this number.
*/

// Time: O(n)
int countGoodPair(vector<int> &nums)
{
    // create a vector of size maxElement + 1 and init with all 0
    int max = *max_element(nums.begin(), nums.end());
    vector<int> freq(max + 1, 0);

    // count frequency of each element in nums
    for (int i = 0; i < nums.size(); i++)
        freq[nums[i]]++;

    // logic: If a number appears n times, then n * (n – 1) / 2 good pairs
    int result = 0;
    for (int i = 0; i < freq.size(); i++)
        result += (freq[i] * (freq[i] - 1) / 2);

    // answer
    return result;
}

// Driver code
int main()
{
    // Given vector
    vector<int> nums{1, 1, 1, 1};

    // fn call
    cout << countGoodPair(nums);
}