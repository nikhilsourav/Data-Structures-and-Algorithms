// https://www.youtube.com/watch?v=abZEVCRYZP8

#include <bits/stdc++.h>
using namespace std;

/* ================== Input ===================== */
// test cases for competitive programming
void input()
{
    int testcases;
    cin >> testcases;
    cin.ignore();
    while (testcases--)
    {
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);
        cout << "First: " << str1 << "\nSecond: " << str2 << "\n";
    }
}

// input separated by space
void cinInput()
{
    string str;
    cout << "Input with cin: ";
    cin >> str;
    cout << "Your Input = " << str << "\n";
}

// input separated by enter
void getlineInput()
{
    string str;
    cout << "Input with getline: ";
    getline(cin, str);
    cout << "Your Input = " << str << " \n";
}

/* ================== Insert ======================= */
// insert(a, b). a = index at which string is inserted, b = string to insert
void insert()
{
    string str = "BestBest";
    str.insert(4, "Of");
    cout << str << "\n";
}

/* ================== Concatenation ======================= */
// plus operator
void concatPlus()
{
    string str1 = "Hello ", str2 = "user!";
    cout << str1 + str2 << "\n";
}

// append function
void concatAppend()
{
    string str1 = "Leet", str2 = "code";
    str1.append(str2);
    cout << str1 << "\n";
}

/* ================== Compare ======================= */
// compares lexicographically
void compare()
{
    string str1 = "abc", str2 = "def";
    if (str1 > str2)
        cout << "Greater\n";
    else if (str1 < str2)
        cout << "Smaller\n";
    else
        cout << "Same\n";
}

/* ================== Find ======================= */
// output first occurance.
void find()
{
    string str = "geeksforgeeks";
    cout << str.find("f");
}

// if string not present find returns (string::npos)
void findAbsent()
{
    string str = "leetcode";
    if (str.find("e") != string::npos)
        cout << "Present\n";
    else
        cout << "Absent\n";
}

/* ================== Erase ======================= */
// erase(startIdx, length). If no b supplied erase from [startIdx to end]
void erase()
{
    string str = "codeforces";
    str.erase(4, 3);
    cout << str << "\n";
}

/* ================== Substring ======================= */
// substr(startIdx, length) If no b supplied print from [startIdx to end]
void substring()
{
    string str = "hackerrank";
    cout << str.substr(5, 5) << "\n";
}

/* ================== Sort ======================= */
void sorting()
{
    string str = "saldkfsdna";
    sort(str.begin(), str.end());
    cout << str << "\n";
}

/* ================== check rotated ======================= */
// check if str2 is a rotation of str1
void rotatedStr()
{
    string str1 = "ABCD", str2 = "CDAB";
    cout << (str1.size() == str2.size() && (str1 + str1).find(str2) != string::npos);
}

/* ================== regex ======================= */
void regexExp()
{
    // Given string
    string baseString = "GeekI24YouQ87Out";

    // regex logic
    regex regexExpression("[a-z][A-Z][0-9]");

    // keep track of matched words
    smatch matched;

    // find all matching strings
    while (regex_search(baseString, matched, regexExpression))
    {
        cout << "Matched word is : " << matched.str() << endl;

        baseString = matched.suffix();
    }
}

// Driver code
int main()
{
    // run any fn
    regexExp();
}