// https://laasyasettyblog.hashnode.dev/juggling-algorithm-for-array-rotation

#include <bits/stdc++.h>
using namespace std;

// find GCD of size and k
int getGcd(int a, int b)
{
    // base case
    if (b == 0)
        return a;

    // recursion
    return getGcd(b, a % b);
}

// left rotate by k = right rotate by size - k
void leftRotate(int arr[], int size, int k)
{
    // if k > size
    k %= size;

    // set unit for right rotation
    k = size - k;

    // get GCD
    int gcd = getGcd(size, k);

    // store temporary vars
    int first, second, third;

    // left rotate juggling algorithm
    for (int i = 0; i < gcd; i++)
    {
        // store first element
        first = arr[i];

        // store i'th element
        third = i;

        // logic:
        while (true)
        {
            second = third + k;
            if (second >= size)
                second -= size;
            if (second == i)
                break;
            arr[third] = arr[second];
            third = second;
        }

        // first element to correct position
        arr[third] = first;
    }
}

// utility fn
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    // fn call
    leftRotate(arr, size, k);

    // print
    print(arr, size);
}