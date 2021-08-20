#include <bits/stdc++.h>
using namespace std;

// book structure
struct Book
{
    string name;
    int price;
};

// Driver code
int main()
{
    // instance of structure
    Book b1 = {"DSA", 799}; //Single structure variable
    Book *ptr1;             //Pointer of Structure type
    ptr1 = &b1;

    // output
    cout << ptr1->name << " " << ptr1->price << "\n";

    // instance of structure
    Book b2;
    b2.name = "OOPS";
    b2.price = 1299;

    Book *ptr2;
    ptr2 = &b2;

    // output
    cout << ptr2->name << " " << ptr2->price << "\n";
}

/*
    To access members of structure using the structure variable, 
    we used the dot . operator. But when we have a pointer of structure 
    type, we use arrow -> to access structure members.
*/