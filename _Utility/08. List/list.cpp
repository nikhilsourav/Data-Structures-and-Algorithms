#include <bits/stdc++.h>
using namespace std;

// print elements of list container
void printList(list<int> myList)
{
    list<int>::iterator itr;
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

    /*
      =============== INITIALIZATION ==============
      general init
    */
    list<int> list_3{1, 2, 3};
    list<int> list_4 = {1, 2, 3};

    // init from vector (same for other containers)
    vector<int> v1 = {5, 6, 7};
    list<int> list_5{v1.begin(), v1.end()};

    // =============== METHODS ============== //
    list<int> intList{2, 3, 4};
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