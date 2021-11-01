/*
    Given weights and values of N items, we need to 
    put these items in a knapsack of capacity W to 
    get the maximum total value in the knapsack.
*/

#include <bits/stdc++.h>
using namespace std;

// Macros
#define all(x) begin(x), end(x)
#define dbl double
#define vpdbl vector<pair<dbl, dbl>>

// Find max possible value under given weight
dbl fractionalKnapsack(vpdbl wgtVal, dbl capacity)
{
    // init res
    dbl res = 0;

    // sort by increasing order of value to maximize result
    sort(all(wgtVal), [&](pair<dbl, dbl> a, pair<dbl, dbl> b)
         { return (a.second / a.first) > (b.second / b.first); });

    // logic:
    for (dbl i = 0; i < wgtVal.size(); i++)
    {
        // if current weight > capacity
        if (wgtVal[i].first > capacity)
        {
            res += (capacity / wgtVal[i].first) * wgtVal[i].second;
            return res;
        }
        // else keep adding values and update capacity
        else
        {
            capacity -= wgtVal[i].first;
            res += wgtVal[i].second;
        }
    }

    // return ans
    return res;
}

// Driver code
int main()
{
    // Given vector of weight-values pair
    vpdbl wgtVal = {{4, 25}, {12, 75}, {2, 15}, {18, 95}, {15, 80} , {6,40},{5,35}};
    dbl capacity = 48;

    // fn call
    cout << fractionalKnapsack(wgtVal, capacity);
}

/*
    ALGORITHM:

    1. Calculate ratio (value/weight) for every item
    2. Sort all item in decreasing order of ratio
    3. Initialize res = 0
    4. Do the following for every item I in sorted order
        if(I.weight > capacity)
        {
            res += (capacity / I.weight) * I.value
            return res;
        }
        else
        {
            capacity -= I.weight;
            res += I.value;
        }
    5. return res
*/