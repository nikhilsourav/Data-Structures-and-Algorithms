/*
    Given a sorted array of positive integers. 
    Your task is to rearrange  the array elements alternatively
    i.e first element should be max value, second should be min value, 
    third should be second max, fourth should be second min and so on.

    Example 1:

    Input:
    N = 6
    arr[] = {1,2,3,4,5,6}
    Output: 6 1 5 2 4 3
    Explanation: Max element = 6, min = 1, 
    second max = 5, second min = 2, and 
    so on... Modified array is : 6 1 5 2 4 3.

    Example 2:

    Input:
    N = 11
    arr[]={10,20,30,40,50,60,70,80,90,100,110}
    Output:110 10 100 20 90 30 80 40 70 50 60
    Explanation: Max element = 110, min = 10, 
    second max = 100, second min = 20, and 
    so on... Modified array is : 
    110 10 100 20 90 30 80 40 70 50 60.

    explaination https://www.youtube.com/watch?v=ZRoVWxBngX0 2:30

    The trick is we can store 2 elements at one index by 
    arr[i] = (arr[i] + ((arr[maxIndex] % maxElement) / maxElement))
*/

#include <bits/stdc++.h>
using namespace std;

// modify and return maxElement Time: O(n), Space: O(1) constraints
void modify(int *arr, int size)
{
    // find maxElement + 1 (in this case it is arr[size-1] + 1, since given array is sorted)
    int maxElement = arr[size - 1] + 1;

    // modify given array to store two value at one index
    int i = 0, minIndex = 0, maxIndex = size - 1;
    while (i < size)
    {
        if (i % 2 == 0)
        {
            arr[i] += arr[maxIndex] % maxElement * maxElement;
            maxIndex--;
        }
        else
        {
            arr[i] += arr[minIndex] % maxElement * maxElement;
            minIndex++;
        }
        i++;
    }

    /* =============== see what's hapenning ================== */
    /*
    // output modified array
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    // modulo with maxElement gives original array
    cout << "\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] % maxElement << " ";

    // division with maxElement gives rearranged order
    cout << "\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] / maxElement << " ";
    */

    // rearrange
    for (int i = 0; i < size; i++)
        arr[i] /= maxElement;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    modify(arr, size);

    // output
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}