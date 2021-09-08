/*
    Given a number n, print first n number
    (in increasing order) such that all 
    these numbers have digits in set {5, 6}
*/

#include <bits/stdc++.h>
#include <queue>
using namespace std;

// fn to print first n num with {5, 6}
void printFirstN(int n)
{
    // create a queue of string
    queue<string> q;

    // init with 5 and 6
    q.push("5");
    q.push("6");

    // logic:
    for (int i = 0; i < n; i++)
    {
        // peek to current front
        string curr = q.front();

        // print current front
        cout << curr << " ";

        // pop current front
        q.pop();

        // push 5 and 6 for next itr
        q.push(curr + "5");
        q.push(curr + "6");
    }
}

// Driver code
int main()
{
    // Given number
    int n = 10;

    // fn call
    printFirstN(n);
}
