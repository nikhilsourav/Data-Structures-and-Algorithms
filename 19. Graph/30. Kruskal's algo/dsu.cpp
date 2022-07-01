/*
    Practice problem: https://bit.ly/3ntgcel
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

/*
    Disjoint set union / Union find

    It is a data structure that keeps track of elements which are
    split into one or more disjoint sets. It has two primary
    operations: find and union

    make(x)    => creates a new set consisting of the new element x
    find(v)    => returns the representative (also called leader)
                   of the set that contains the element v
    union(a,b) => merges two different sets (set in which a is
                   located and set in which b is located)

    Terms:
        1. Path compression
        2. Union by size/rank

    Uses:
        1. Kruskal's minimum spanning tree
        2. Grid percolation
        3. Network connectivity
        4. Least common ancestor in tree
        5. Image processing
*/

// Global parent and size array
int parent[MAX];
int size[MAX];

// Make set with new element
void make_set(int v)
{
    parent[v] = v;
    ::size[v] = 1;
}

// Find representative
int find_rep(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find_rep(parent[v]); // path compression
}

// Union two sets
void union_sets(int a, int b)
{
    a = find_rep(a); // a is now representative of 'a' set
    b = find_rep(b); // b is now representative of 'b' set

    if (a != b)
    {
        // Union by size: always join smaller tree to bigger one
        if (::size[a] < ::size[b])
            swap(a, b);         // ensure b is always smaller
        parent[b] = a;          // join b -> a
        ::size[a] += ::size[b]; // size of a increases by b
    }
}

// Driver code
int main()
{
    /*

    Given:
        vertices = 8
        edges = 5
        sets = 3

    cnt:      1    2    3
    set:    1-2-7 3-5 4-8-6

    connected components = 3

    */

    int vertices = 8, edges = 5;

    // initialize sets of distinct elements (i)
    for (int i = 1; i <= vertices; i++)
        make_set(i);

    // 1 - 2 - 7
    union_sets(1, 2);
    union_sets(2, 7);

    // 3 - 5
    union_sets(3, 5);

    // 4 - 8 - 6
    union_sets(4, 8);
    union_sets(8, 6);

    // find connected components
    int cc = 0;
    for (int i = 1; i <= vertices; i++)
        if (find_rep(i) == i)
            cc++;

    cout << "Total number of disjoint sets: " << cc << endl;
}