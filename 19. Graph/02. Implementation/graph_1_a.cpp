/*
    https://bit.ly/3fO0mr1

    =================== Edge List Representation ==================

    Vertex is a vector of char
        - This stores name of each vertex
        - Here we've assumed that vertex name has only one character

    Edge is a vector of pair of character
        - Each cell in the vector denote connection between two vertices
        - If there is a connection between A and B, we'll store them in edgeList
        - If there is no connection between A and B, we simply don't store it
        - Instead of pair, we could have used structure as well
        - Storing name of each vertex is not ideal
        - This is because name can be large thus each cell will have unpredictable size
        - A better approach would be using reference instead of vertex name
        - Here we've used name itself. In the next implementation we've used indices

    Space Complexity:
        O(|v| + |E|) or O(num of vertices + num of edges)

    Time Complexity:
        Find adjacent node: O(|E|)
        Check if given nodes are connected: O(|E|)

    In a graph anything running on O(|E|) is considered very costly
    We often want to keep the complexity in the order of O(|V|)

    Pros: Good Space Complexity O(|v| + |E|)
    Cons: Poor Time Complexity O(|E|) for frequent operations
*/
#include <bits/stdc++.h>
using namespace std;

// Graph structure undirected and unweighted
struct Graph
{
    vector<char> vertex;
    vector<pair<char, char>> edges;
};

// Driver code
int main()
{
    // create a graph
    Graph g1;

    // add vertices
    g1.vertex.push_back('A');
    g1.vertex.push_back('B');
    g1.vertex.push_back('C');
    g1.vertex.push_back('D');
    g1.vertex.push_back('E');
    g1.vertex.push_back('F');
    g1.vertex.push_back('G');
    g1.vertex.push_back('H');

    // add edges
    g1.edges.push_back({'A', 'B'}); // edge A-B
    g1.edges.push_back({'A', 'C'}); // edge A-C
    g1.edges.push_back({'A', 'D'}); // edge A-D
    g1.edges.push_back({'B', 'E'}); // edge B-E
    g1.edges.push_back({'B', 'F'}); // edge B-F
    g1.edges.push_back({'C', 'G'}); // edge C-G
    g1.edges.push_back({'D', 'H'}); // edge D-H
    g1.edges.push_back({'E', 'H'}); // edge E-H
    g1.edges.push_back({'F', 'H'}); // edge F-H
    g1.edges.push_back({'G', 'H'}); // edge G-H
}