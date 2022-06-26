/*
    https://bit.ly/3fO0mr1

    =================== Edge List Representation ==================

    vertexList is a vector of string
        - This stores name of each vertex
        - Here name of each vertex is a string

    edgeList is a vector of Edge structure
        - Each cell in the vector contains
            startIndex (index of first/origin vertex)
            endIndex (index of second/destination vertex)
            weight (weight/cost of the edge)
        - Efficient than previous implementation as size of each edge is same
        - This is because storing index of vertex allow fetching vertex name in O(1) time

    Space Complexity:
        O(|v| + |E|) or O(num of vertices + num of edges)

    Time Complexity:
        Find adjacent node: O(|E|)
        Check if given nodes are connected: O(|E|)

    In a graph anything running on O(|E|) is considered very costly
    We often want to keep the complexity in order of O(|V|) so this design is not good

    Pros: Good Space Complexity O(|v| + |E|), minor space improvement over previous method
    Cons: Poor Time Complexity O(|E|) for frequent operations
*/
#include <bits/stdc++.h>
using namespace std;

// Edge structure
struct Edge
{
    int startVertex;
    int endVertex;
    int weight;
};

// Graph structure undirected and unweighted
struct Graph
{
    vector<string> vertexList;
    vector<Edge> edgeList;
};

int main()
{
    // create a graph
    Graph g1;

    // add vertices
    g1.vertexList.push_back("America");
    g1.vertexList.push_back("Boston");
    g1.vertexList.push_back("Canada");
    g1.vertexList.push_back("Denmark");
    g1.vertexList.push_back("Europe");
    g1.vertexList.push_back("Finland");
    g1.vertexList.push_back("Ghana");
    g1.vertexList.push_back("Hungary");

    // add edges

    // Edge A-B
    Edge e1;
    e1.startVertex = 0;        // index of A in vertex list
    e1.endVertex = 1;          // index of B in vertex list
    e1.weight = 5;             // weight of Edge A-B
    g1.edgeList.push_back(e1); // push this Edge in list

    // Edge A-C
    Edge e2;
    e2.startVertex = 0;        // index of A in vertex list
    e2.endVertex = 2;          // index of C in vertex list
    e2.weight = 7;             // weight of Edge A-C
    g1.edgeList.push_back(e2); // push this Edge in list

    // Edge A-D
    Edge e3;
    e3.startVertex = 0;        // index of A in vertex list
    e3.endVertex = 3;          // index of D in vertex list
    e3.weight = 3;             // weight of Edge A-D
    g1.edgeList.push_back(e3); // push this Edge in list

    // Edge B-E
    Edge e4;
    e4.startVertex = 1;        // index of B in vertex list
    e4.endVertex = 4;          // index of E in vertex list
    e4.weight = 2;             // weight of Edge B-E
    g1.edgeList.push_back(e4); // push this Edge in list

    // Edge B-F
    Edge e5;
    e5.startVertex = 1;        // index of B in vertex list
    e5.endVertex = 5;          // index of F in vertex list
    e5.weight = 10;            // weight of Edge B-F
    g1.edgeList.push_back(e5); // push this Edge in list

    // Edge C-G
    Edge e6;
    e6.startVertex = 2;        // index of C in vertex list
    e6.endVertex = 6;          // index of G in vertex list
    e6.weight = 1;             // weight of Edge C-G
    g1.edgeList.push_back(e6); // push this Edge in list

    // Edge D-H
    Edge e7;
    e7.startVertex = 3;        // index of D in vertex list
    e7.endVertex = 7;          // index of H in vertex list
    e7.weight = 11;            // weight of Edge D-H
    g1.edgeList.push_back(e7); // push this Edge in list

    // Edge E-H
    Edge e8;
    e8.startVertex = 4;        // index of E in vertex list
    e8.endVertex = 7;          // index of H in vertex list
    e8.weight = 9;             // weight of Edge E-H
    g1.edgeList.push_back(e8); // push this Edge in list

    // Edge F-H
    Edge e9;
    e9.startVertex = 5;        // index of F in vertex list
    e9.endVertex = 7;          // index of H in vertex list
    e9.weight = 4;             // weight of Edge F-H
    g1.edgeList.push_back(e9); // push this Edge in list

    // Edge G-H
    Edge e10;
    e10.startVertex = 6;        // index of G in vertex list
    e10.endVertex = 7;          // index of H in vertex list
    e10.weight = 6;             // weight of Edge G-H
    g1.edgeList.push_back(e10); // push this Edge in list
}