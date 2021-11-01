/*
    Basics of vector

    https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/
*/

#include <bits/stdc++.h>
using namespace std;

// Print vector elements
void print(vector<int> vect)
{
    for (auto &it : vect)
        cout << it << ' ';
    cout << "\n";
}

// Driver code
int main()
{
    // vector input
    vector<int> vect;
    for (auto &it : vect)
        cin >> it;

    // 1. Initializing by pushing values one by one :
    vector<int> vect_1;
    vect_1.push_back(1);
    vect_1.push_back(1);
    vect_1.push_back(1);

    // 2. Specifying size (n) and initializing all values (as 10)
    int n = 3;
    vector<int> vect_2(n, 2);

    // 3. Initializing like arrays :
    vector<int> vect_3{3, 3, 3};

    // 4. Initializing from an array :
    int arr[] = {4, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect_4(arr, arr + size);

    // 5. Initializing from another vector :
    vector<int> vect_temp_1{5, 5, 5};
    vector<int> vect_5(vect_temp_1.begin(), vect_temp_1.end());

    // 6. Initializing all elements with a particular value :
    vector<int> vect_6(10);
    int value = 6;
    fill(vect_6.begin(), vect_6.end(), value);

    // Output
    cout << "====== First Vector ========\n";
    print(vect_1);
    cout << "====== Second Vector ========\n";
    print(vect_2);
    cout << "====== Third Vector ========\n";
    print(vect_3);
    cout << "====== Fourth Vector ========\n";
    print(vect_4);
    cout << "====== Fifth Vector ========\n";
    print(vect_5);
    cout << "====== Sixth Vector ========\n";
    print(vect_6);
}
