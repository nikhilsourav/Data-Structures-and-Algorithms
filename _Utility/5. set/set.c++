/*
    https://www.geeksforgeeks.org/set-in-cpp-stl/
    https://www.youtube.com/watch?v=7mx2BasNK0w

    * Sets are a type of associative containers in which 
      each element has to be unique, because the value of 
      the element identifies it.
    
    * The value of the element cannot be modified once it 
      is added to the set, though it is possible to remove
      and add the modified value of that element. 
*/

#include <bits/stdc++.h>
using namespace std;

// print unordered_set values using range loop
void print_1(unordered_set<string> stringSet)
{
  cout << "\nValues of unordered_set:\n";

  // print logic:
  for (auto val : stringSet)
    cout << val << " ";

  cout << "\n";
}

// print unordered_set value using iterator
void print_2(unordered_set<string> stringSet)
{
  unordered_set<string>::iterator it;

  cout << "\nValues of unordered_set:\n";

  // print logic:
  for (it = stringSet.begin(); it != stringSet.end(); it++)
    cout << (*it) << " ";

  cout << "\n";
}

// print set values using range loops
void print_3(set<int> intSet)
{
  cout << "\nValues of set:\n";

  for (auto itr : intSet)
    cout << itr << " ";

  cout << "\n";
}

// print set values using iterator
void print_4(set<int> intSet)
{
  set<int>::iterator itr;

  cout << "\nValues of set:\n";

  for (itr = intSet.begin(); itr != intSet.end(); itr++)
    cout << *itr << " ";

  cout << "\n";
}

// Driver code
int main()
{
  /*
    ================= DECLARE UNORDERED_SET =================
    Declare unorderd set O(1)
    Implementated using hashing
    Ensure no duplicate
    Not stored in order
  */
  cout << "============== unordered_set ==================\n";
  unordered_set<string> stringSet;

  /*
    ========================= INSERT =========================
    insert (generally used with loops)
  */
  stringSet.insert("abc");
  stringSet.insert("def");

  /*
    ========================= SIZE =========================
    set.empty() returns true or false
    set.size() return size
  */
  if (!stringSet.empty())
    cout << "Size: " << stringSet.size() << "\n";
  else
    cout << "\nSet is empty\n";

  /*
    ========================= PRINT =========================
    print using any fn 
    print_1 uses range loop
    print_2 uses iterator
  */
  print_1(stringSet);

  /*
    ========================= FIND =========================
    set.find()
    returns iterator pointing to value if found
    otherwise return iterator pointing to set.end()
  */
  unordered_set<string>::iterator it = stringSet.find("abc");

  // always check before use:
  if (it != stringSet.end())
    cout << "\nFound: " << *it << "\n";
  else
    cout << "\nNot Present\n";

  /*
    ========================= CLEAR =========================
    set.clear() 
    deletes all value of the set 
    reduces set.size() to zero
  */
  stringSet.clear();

  /*
    ========================= DECLARE SET =========================
    operations O(log(n))
    Implemented using Red Black Tree
    Ensure no duplicate
    Stored in order
  */
  cout << "\n============== set ==================\n";
  set<int> intSet;

  /*
    ========================= INSERT =========================
  */
  intSet.insert(1);
  intSet.insert(2);
  intSet.insert(3);
  intSet.insert(4);
  intSet.insert(5);

  /*
    ========= Other operations are similier to unorderd set ===========
  */

  /*
    ============= Delete Element upto 3 =========================
  */
  intSet.erase(intSet.begin(), intSet.find(3));
  cout << "\nDelete elements upto 3\n";
  print_3(intSet);
}