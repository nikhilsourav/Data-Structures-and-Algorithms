/*
    Check if a string has balanced paranthesis
    eg: str = "()(]" => false
*/

#include <bits/stdc++.h>
using namespace std;

// Match two chars as balanced parantheseis
bool matching(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

// Check if string has balanced paranthesis
bool isBalanced(string str)
{
    // init stack
    stack<char> stk;

    // logic:
    for (int i = 0; i < str.length(); i++)
    {
        // if str[i] is opening bracket push in stack
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            stk.push(str[i]);
        // otherwise check if s.top contains closing bracket
        else
        {
            // if string is like this ')()[]'
            if (stk.empty() == true)
                return false;
            // match top of stack with str[i]
            else if (matching(stk.top(), str[i]) == false)
                return false;
            // if matched pop stack and continue
            else
                stk.pop();
        }
    }

    // if stack is empty => given string is balanced
    return (stk.empty() == true);
}

// Driver code
int main()
{
    // Given string
    string str = "{()}[]";

    // fn call
    cout << boolalpha << isBalanced(str);
}
