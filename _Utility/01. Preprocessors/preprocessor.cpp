// https://www.geeksforgeeks.org/cc-preprocessors/

#include <bits/stdc++.h>
/*
    #
        symbolizes that this statement has to pass through preprocessor before compiling

    include
        execute inclusion of inbuilt files. syntax: (#include <file_name>)
        or user defined custom files. syntax: (#include "file_name")

    bits/stdc++.h
        includes all inbuilt files like <iostream> <algorithm> etc
*/

using namespace std;
/*
    'using namespace' means that in the current scope,
    make all the things under the std namespace available without having 
    to prefix std:: before each of them.
*/

#define print(x) cout << x << "\n";
#define pi 3.14
/*
    #define
        It is a macro that gets replaced with its defination at compile time.
        The value of macro can't be changed at runtime
    
    parameterised
        #define print(x) is a parameterized macro
    
    Non-parameterised
        #define pi 3.13 is a non-parameterised macro
*/

#define all(x) x.begin(), x.end()
/*
    We can create custom macros to save time

    The above macro can be used in various ways:

        vector <int> vect {3, 2, 1, 3};

        sort(all(vect))

        binary_search(all(vect), k);

        set <int> counter (all(vect));
    
        fill(all(vect), 1);
*/

// Driver code
int main()
{
    auto adder = [&](const int x, const int y) { return x + y; };
    cout << adder(6, 4);
    /*
        Lambda function is used to write short functions. It has three parts:

        []
            Used to capture values at compile time or runtime. '&' ensures variables
            don't get copied unintentionally.

        (int x, int y)
            Defines arguments. 'const' is used to ensure variables remain unchanged

        {return x + y; };
            return statement for the function. Notice the semicolon.

        eg 1:
            sort(all(vect), [&] (int x, int y) { return x == y ? x : x < y; });

        eg 2:
            sort(begin(vectPair), end(vectPair), [&](pair<int, int> a, pair<int, int> b)
            { return a.second != b.second ? a.second > b.second : a.first < b.first; });
    */
}