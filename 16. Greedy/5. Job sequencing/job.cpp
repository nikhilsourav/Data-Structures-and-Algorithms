/*
    https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

    Given a set of N jobs where each job i has a deadline a
    nd profit associated to it. Each job takes 1 unit of 
    time to complete and only one job can be scheduled at a 
    time. We earn the profit if and only if the job is completed 
    by its deadline. The task is to find the maximum profit and 
    the number of jobs done.
*/
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;       // job id
    int deadline; // deadline of job
    int profit;   // profit if job is finished before deadline
};

// Function to find number of jobs done and maximum profit
vector<int> JobScheduling(Job arr[], int n)
{
    // sort by decreasing order of profit
    sort(arr, arr + n, [&](Job a, Job b)
         { return a.profit > b.profit; });

    // max deadline
    int maxDeadline = arr[0].deadline;
    for (int i = 1; i < n; i++)
        maxDeadline = max(maxDeadline, arr[i].deadline);

    // slot array of size maxDeadline + 1
    int slot[maxDeadline + 1];

    // init slot with all -1
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    // init countter for no. of job and max profit
    int countJobs = 0, maxProfit = 0;

    // logic:
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countJobs++;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }

    // vector ans with two elements: {no. of jobs, max profit}
    return {countJobs, maxProfit};
}

// Driver code
int main()
{
    // create job objects
    Job j1 = {1, 2, 85};
    Job j2 = {2, 1, 15};
    Job j3 = {3, 7, 90};
    Job j4 = {4, 5, 45};
    Job j5 = {5, 3, 65};
    Job j6 = {6, 1, 25};
    Job j7 = {7, 2, 15};
    Job j8 = {8, 4, 75};
    Job j9 = {9, 5, 35};
    Job arr[] = {j1, j2, j3, j4, j5, j6, j7, j8, j9};

    // total jobs
    int n = 9;

    // fn call
    vector<int> ans = JobScheduling(arr, n);

    // output
    for (auto &val : ans)
        cout << val << " ";
}
/*
    ALGORITHM:

    1. Sort jobs in decreasing order of profit
    2. Initialize res as first job and assign latest possible job
    3. Do the following for remaining (n-1) jobs
        a. If this job can't be added => ignore
        2. Else add to latest possible slot
*/