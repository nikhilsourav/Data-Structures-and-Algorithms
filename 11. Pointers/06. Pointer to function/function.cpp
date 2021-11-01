#include <bits/stdc++.h>
using namespace std;

// Sum two vars
int sum(int n1, int n2)
{
    return n1 + n2;
}

// Driver code
int main()
{
    // Given number
    int num1 = 10, num2 = 20;

    // Declare pointer to function
    int (*ptr_to_sum)(int n1, int n2);

    // Store sum function in this pointer
    ptr_to_sum = sum;

    // Output
    cout << ptr_to_sum(num1, num2);
}

/*
    NOTES:

    ================== pointer to a function ==================
    It is possible to declare a pointer pointing to a function which 
    can then be used as an argument in another function. A pointer to 
    a function is declared as follows,

    type (*pointer-name)(parameter);
    int (*sum)();   // correct
    int *sum();     // Incorrect

    =========== Problem with function returning pointer ============
    * A function can also return a pointer to the calling function. 

    * In this case you must be careful, because local variables of 
      function doesn't live outside the function. 

    * They have scope only inside the function. 

    * Hence if you return a pointer connected to a local variable, 
     that pointer will be pointing to nothing when the function ends.

    =========================== solution ============================
    * Either use argument with functions. Because argument passed to 
      the functions are declared inside the calling function, hence 
      they will live outside the function as well.

    * Or, use static local variables inside the function and return them. 
      As static variables have a lifetime until the main() function exits, 
      therefore they will be available througout the program.
*/