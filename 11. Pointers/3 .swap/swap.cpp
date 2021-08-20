#include <bits/stdc++.h>
using namespace std;

// swap two numbers using pointer
void swapByPointer(int *ptr1, int *ptr2)
{
    // init temp number
    int temp;

    // swap
    temp = *ptr1;  // store value of ptr1 in temp
    *ptr1 = *ptr2; // store value of ptr2 in ptr1
    *ptr2 = temp;  // store value of temp in ptr2
}

// swap two numbers using ref
void swapByRef(int &ptr1, int &ptr2)
{
    // init temp number
    int temp;

    // swap
    temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

// Driver code
int main()
{
    // Given numbers
    int num1 = 5, num2 = 7;

    // fn call
    swapByPointer(&num1, &num2);
    // swapByRef(num1, num2);

    // output
    cout << num1 << " " << num2;
}