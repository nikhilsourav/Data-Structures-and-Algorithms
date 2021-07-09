#include <bits/stdc++.h>
using namespace std;

// find max number of guests you can meet
int maxGuest(int arrival[], int departure[], int n)
{
    // sort given function
    sort(arrival, arrival + n);
    sort(departure, departure + n);

    // init vars after 1st arrival:
    int i = 1, j = 0, res = 1, curr = 1;

    // logic similar to merge two array:
    while (i < n && j < n)
    {
        // when arr < dep increase count of geusts
        if (arrival[i] <= departure[j])
        {
            curr++;
            i++;
        }
        // when dep > arr decrease count of guests
        else
        {
            curr--;
            j++;
        }

        // find maximum count
        res = max(curr, res);
    }

    // answer
    return res;
}

// Driver code
int main()
{
    // Given time
    int arrival[] = {900, 600, 700};
    int departure[] = {1000, 800, 730};
    int n = sizeof(arrival) / sizeof(arrival[0]);

    // fn call
    cout << maxGuest(arrival, departure, n);
}

/*
    Time   Arr/Dep    count of guest
    6:00    Arrival    1
    7:00    Arrival    2            (Answer)
    7:30    Depart     1
    8:00    Depart     0
    9:00    Arrival    1
    10:00   Depart     0
*/