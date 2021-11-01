/*
    Basics of array, Insert, Search, Delete etc
*/

#include <bits/stdc++.h>
using namespace std;

// Linear search for first occurance of element O(n)
int search(int arr[], int size, int item)
{
    // search
    for (int i = 0; i < size; i++)
        if (arr[i] == item)
            return i;

    // if not found
    return -1;
}

// Insert element at index O(n)
bool insert(int arr[], int size, int item, int position, int capacity)
{
    // if array already filled
    if (size == capacity)
        return false;

    // initialize index
    int index = position - 1;

    // move all elements after index to 1 block right
    for (int i = size - 1; i >= index; i--)
        arr[i + 1] = arr[i];

    // insert at position
    arr[index] = item;

    // confirmation
    return true;
}

// Delete first occurance of elemet at index O(n)
void deleteElement(int *arr, int size, int position)
{
    // index is position - 1
    int index = position - 1;

    // move all elements from index to left
    for (int i = index; i < size; i++)
        arr[i] = arr[i + 1];
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int capacity = sizeof(arr) / sizeof(arr[0]);

    // Get i-th or update i-th element
    int el = arr[8]; // O(1)
    arr[2] = 3;      // O (1)

    // Search
    int found = search(arr, 10, capacity);
    cout << "======== search ========\n";
    (found == -1) ? cout << "Not found\n" : cout << "index: " << found << "\n";

    // Insert
    cout << "======== insert ========\n";
    bool inserted = insert(arr, 10, 231, 3, capacity);
    if (inserted)
        for (int i = 0; i < capacity; i++)
            cout << arr[i] << " ";
    else
        cout << "Already full\n";
    cout << "\n";

    // Delete
    cout << "======== delete ========\n";
    deleteElement(arr, capacity, 3);
    for (int i = 0; i < capacity - 1; i++)
        cout << arr[i] << " ";
    cout << "\n";
}