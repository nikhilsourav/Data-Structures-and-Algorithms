/*
    Given an array of names (consisting of lowercase characters) of 
    candidates in an election. A candidate name in array represents 
    a vote casted to the candidate. Print the name of candidate that
    received Max votes. If there is tie, print lexicographically smaller name.
*/

#include "bits/stdc++.h"
using namespace std;

// Find winner
vector<string> findWinner(vector<string> &votes)
{
    // insert all votes in a map
    map<string, int> counter;
    for (auto &str : votes)
        counter[str]++;

    // traverse through map to find the candidate with maximum votes.
    int maxValueInMap = 0;
    string winner;
    for (auto &entry : counter)
    {
        string key = entry.first;
        int val = entry.second;
        if (val > maxValueInMap)
        {
            maxValueInMap = val;
            winner = key;
        }

        // If there is a tie, pick lexicographically smaller.
        else if (val == maxValueInMap && winner > key)
            winner = key;
    }

    // export answer
    vector<string> answer;
    answer.push_back(winner);
    answer.push_back(to_string(maxValueInMap));
    return answer;
}

// Driver code
int main()
{
    // Given vector
    vector<string> votes = {"john", "johnny", "jackie", "johnny", "john", "jackie",
                            "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"};

    // fn call
    vector<string> answer = findWinner(votes);

    // Output
    cout << answer[0] << " won by " << answer[1] << " total votes";
}
