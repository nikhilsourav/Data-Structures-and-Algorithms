#include <bits/stdc++.h>
using namespace std;

// print unordered_map values using iterator
void print_1(unordered_map<int, string> stringMap)
{
    cout << "\n";
    unordered_map<int, string>::iterator it;
    for (it = stringMap.begin(); it != stringMap.end(); it++)
        cout << (*it).first << " " << (*it).second << "\n";
    cout << "\n";
}

// print unordered_map values using range loop
void print_2(unordered_map<int, string> stringMap)
{
    cout << "\n";
    for (auto it : stringMap)
        cout << it.first << " " << it.second << "\n";
    cout << "\n";
}

// print map value using interator
void print_3(map<int, int> intMap)
{
    cout << "\n";
    map<int, int>::iterator it;
    for (it = intMap.begin(); it != intMap.end(); it++)
        cout << (*it).first << " " << (*it).second << "\n";
    cout << "\n";
}

// print map value using range loop
void print_4(map<int, int> intMap)
{
    cout << "\n";
    for (auto it : intMap)
        cout << it.first << " " << it.second << "\n";
    cout << "\n";
}

// Driver code
int main()
{
    // ===================== Unordered map ============================ //
    // Implemented using Hashing, O(1)
    // Complicated data not allowed)
    unordered_map<int, string> stringMap;

    // ============= Insert O(1) ============ //
    stringMap[1] = "abc";
    stringMap[5] = "cdc";
    stringMap.insert(make_pair(3, "acc"));
    stringMap.insert({4, "agc"});

    // ============= print ============== //
    cout << "Content of unordered_map:";
    print_1(stringMap);

    // ============== find ================ //
    // if found return iterator else return map.end()
    auto it = stringMap.find(3);
    if (it == stringMap.end())
        cout << "\nNot Found\n";
    else
        cout << "Found at: " << (*it).first << " Value: " << (*it).second << "\n";

    // ============== erase =============== //
    // takes key or iterator
    stringMap.erase(3);                 // by key
    stringMap.erase(stringMap.find(4)); // by iterator
    cout << "\nAfter erasing:";
    print_1(stringMap);

    // ========================= map ============================ //
    // Implemented using Red Black, Tree O(1)
    // Complecated data allowed
    map<int, int> intMap;
    intMap[1] = 1;
    intMap[2] = 3;
    intMap.insert({3, 5});
    intMap.insert(make_pair(4, 1));

    // ========= erase =========== //
    intMap.erase(4);                              // by value
    intMap.erase(intMap.begin(), intMap.find(2)); // by iterator

    // ========== print ========= //
    cout << "\nContents of map:";
    print_3(intMap);
}