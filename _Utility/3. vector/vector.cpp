// https://www.geeksforgeeks.org/vector-in-cpp-stl/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define all(x) x.begin(), x.end()

// print vector
void print(vi vect)
{
    // output Traversing the vector using value at iterator
    vi::iterator itr;
    for (itr = vect.begin(); itr != vect.end(); itr++)
        cout << *itr << " ";
    cout << "\n";
}

// input output
void io()
{
    // vector input output
    vi vect;
    int size;
    cout << "size: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        vect.push_back(val);
    }
    for (auto &it : vect)
        cout << it << " ";
}

// ================== 1. Initializing by pushing values one by one : ================== //
void init_1()
{
    // init by pushing back
    vi vect;
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
}

// ======== 2. Specifying size (n) and initializing all values (as 2) ======== //
void init_2()
{
    // size 3, each value = 2
    int n = 3;
    vi vect(n, 2);
}

// ================== 3. Initializing like arrays : ================== //
void init_3()
{
    vi vect = {3, 3, 3};
}

// ================== 4. Initializing from array : ================== //
void init_4()
{
    int arr[] = {4, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    vi vect(arr, arr + size);
}

// ================== 5. Initializing from another vector : ================== //
void init_5()
{
    vi temp{5, 5, 5};
    vi vect(all(temp));
}

// ======== 6. Initializing all elements with a particular value : ======== //
void init_6()
{
    vi vect(10);
    fill(all(vect), 57);
}

// ================== 7. Forward and backward iterator ================== //
void fwdBwdIterator()
{
    // init vect
    vi vect{10, 20, 30};

    // initialize forward iterator
    vi::iterator itr;

    // loop and print
    for (itr = vect.begin(); itr != vect.end(); itr++)
        cout << (*itr) << " ";

    // initialize backward iterator
    vi::reverse_iterator rItr;

    // loop and print
    cout << "\n";
    for (rItr = vect.rbegin(); rItr != vect.rend(); rItr++)
        cout << (*rItr) << " ";
    cout << "\n";
}

// =============== 7. Delete while traversing using some logic =============== //
void traverse()
{
    // init vect
    vi vect{1, 2, 3, 4, 5, 6};

    // Delete while traversing with some logic
    for (auto it = vect.begin(); it != vect.end();)
    {
        // after erasing, erase() points to next element
        if ((*it) % 2 == 0)
            it = vect.erase(it);
        // if we didn't erase an element, move it forward
        else
            it++;
    }
}

// =============== 7. Sum of all elements =============== //
// we can use custom function as 4th parameter for multipy, divide etc
void sum()
{
    vi vect{1, 2, 3, 4, 5};
    int res = 0;
    cout << accumulate(all(vect), res);
}

// Driver code
int main()
{
    // run any fn
    io();
}
