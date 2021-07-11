#include <bits/stdc++.h>
using namespace std;

// define macros
#define vi vector<int>
#define li list<int>
#define all(x) x.begin(), x.end()
#define pt cout <<

// print elements of list container
void printList(li myList)
{
    li::iterator itr;
    for (itr = myList.begin(); itr != myList.end(); itr++)
        cout << *itr << " ";
    cout << "\n";
}

// Driver code
int main()
{
    // create a singly linked list
    forward_list<int> list_1;

    // create doubly linked list
    list<int> list_2;

    // =============== Initialization ============== //
    // general init
    li list_3{1, 2, 3};
    li list_4 = {1, 2, 3};

    // init from vector (same for other containers)
    vi v1 = {5, 6, 7};
    li list_5{all(v1)};

    // =============== methods ============== //
    li intList{2, 3, 4};
    intList.insert(intList.begin(), 1); // at a particular position
    intList.push_back(5);               // at the end of list
    intList.push_front(0);              // at the front of list
    intList.size();                     // gives size
    intList.reverse();                  // reverse list O(n)
    intList.sort();                     // sort in O(nlogn)
    intList.remove(0);                  // remove element
    intList.pop_back();                 // delete last element
    intList.pop_front();                // delete first elemtn
    printList(intList);                 // print list
    intList.clear();                    // erase all elements
}