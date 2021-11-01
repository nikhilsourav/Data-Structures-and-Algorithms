/*
    Given N activities with their start and finish day 
    given in array start[ ] and end[ ]. Select the 
    maximum number of activities that can be performed 
    by a single person, assuming that a person can only 
    work on a single activity at a given day.
*/

#include <bits/stdc++.h>
using namespace std;

// Init macros
#define all(x) begin(x), end(x)
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

// Find max activity
int activitySelection(vi start, vi finish)
{
    // init size
    int n = start.size();

    // vector of pair
    vector<pair<int, int>> vectPair;

    // create vect pair
    for (int i = 0; i < n; i++)
        vectPair.pb({start[i], finish[i]});

    // sort according to finish time
    sort(all(vectPair), [&](pii a, pii b)
         { return a.second < b.second; });

    // pick first activity
    int res = 1;

    // logic:
    int last = 0;
    for (int i = 1; i < n; i++)
    {
        // current activity doesnt overlap => res++, else ignore
        if (vectPair[i].first > vectPair[last].second)
        {
            res++;
            last = i;
        }
    }

    // ans
    return res;
}

// Driver code
int main()
{
    // Given vectors
    vi start = {1, 2, 3, 10};
    vi finish = {3, 4, 8, 11};

    // fn call
    cout << activitySelection(start, finish);
}

/*
    ALGORITHM:

    1. Sort according to finish time
    2. Initialize solution as first activity
    3. Do following for remaining items
        a. if current activity doesn't overlap with last 
           picked activity add this activity to solution

        b. oterhwise ignore
*/