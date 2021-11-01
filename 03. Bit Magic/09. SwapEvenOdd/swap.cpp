/*
    Given an unsigned integer N. The task is to swap all odd bits with even bits.
    For example, if the given number is 23 (00010111), it should be converted to 43(00101011). 

    Algorithm: 
    Obtain the even bits and shift them to odd position
    Obtain the odd bits and shift them to even position
    combine these values using | operators

    Theory:
    0xAAAAAAAA = 32 bit number where even bits = 1 and odd bits = 0
    where A = 1010

    0x55555555 = 32 bit number where even bits = 0 and odd bits = 1
    where 5 = 0101
*/

#include <bits/stdc++.h>
using namespace std;

// Swap in O(1)
int swap(int n)
{
    int evenBits, oddBits, answer;
    evenBits = n & 0xAAAAAAAA;   // gets value of even position
    oddBits = n & 0x55555555;    // gets balue of odd position
    evenBits >>= 1;              // right shift for swap
    oddBits <<= 1;               // right shift for swap
    answer = evenBits | oddBits; // combine both bits
    return answer;
    // https://www.youtube.com/watch?v=GWLCF808oVI
}

// Driver code
int main()
{
    // Given number
    int n = 23;

    // fn call
    cout << swap(n);
}