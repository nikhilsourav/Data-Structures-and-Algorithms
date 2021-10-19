/*
    =========== Direct Address Table ============
    Imagine you have 1000 keys with value from (0 to 999).
    Implement the folling in O(1) time

    1. Search
    2. Insert
    3. Delete

    Example of above operations:

        insert(10)  (inserts 10)
        insert(20)  (inserts 20)
        insert(119) (inserts 119)
        search(10)  (returns true)
        search(20)  (returns true)
        delete(119) (deletes 119)
        search(119) (returns false )

    Problems with this implementation:

        Can't handle large values eg: if phone number is a key
        Can't handle floating points eg: 10.23 is not an index
        Can't handle strings eg: "gfg" can't be an index

*/

#include <bits/stdc++.h>
using namespace std;

// Table to store boolean values init with all 0
bool HASH[1000] = {};

// Insert an elemnt in table
void Insert(int element)
{
    if (element >= 0 && element <= 999)
        HASH[element] = true;
    else
        return;
}

// Delete element from table
void Delete(int element)
{
    if (element >= 0 && element <= 999)
        HASH[element] = false;
    else
        return;
}

// Search element in table
bool Search(int element)
{
    if (element >= 0 && element <= 999)
        return HASH[element];
    return false;
}

// Driver code
int main()
{
    Insert(10);
    Insert(20);
    Insert(119);
    Search(10) == 1 ? cout << "True\n" : cout << "False\n"; // true
    Search(20) == 1 ? cout << "True\n" : cout << "False\n"; // true
    Delete(119);
    Search(119) == 1 ? cout << "True\n" : cout << "False\n"; // false
}