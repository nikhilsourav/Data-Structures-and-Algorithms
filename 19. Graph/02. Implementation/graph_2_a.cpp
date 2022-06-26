/*
    https://bit.ly/3It2i4m

    ================== Adjacency Matrix Representation ==================

    adjacency_matrix is a 2-dimensional matrix that contains edges
        - A value in adj_mat[i][j] is 1 if there is an edge from i to j
        - Otherwise adj_mat[i][j] contains 0
        - In undirected graph if edge i to j exist then j to i will also exist
        - Adjacency Matrix representations is suitable for dense graph
        - A dense graph is a graph where |E| (no of edges) is close to maximum
        - If we want to use weighted graph then set adj_mat[i][j] = weight

    Space Complexity:
        O(|v| * |v|) or O(no of vertices * no of vertices)

    Time Complexity:
        Find adjacent nodes:
            if vertex index is given: O(|v|) simply scan adj_mat for ith row

        Check if given nodes are connected:
            if index is gievn: O(1)

    Pros: Good Time Complexity for frequent operations O(|v|)
    Cons: Poor space complexity O(|E|)
*/
#include <bits/stdc++.h>
using namespace std;

// Graph class undirected and unweighted
class Graph
{
private:
    // total number of vertices in graph
    int number_of_vertices;

    // declare adjacency matrix
    bool **adjacency_matrix;

public:
    // graph constructor
    Graph(int number_of_vertices)
    {
        // receive total number of vertices from user
        this->number_of_vertices = number_of_vertices;

        // initializing adjacency matrix with accurate size and each cell value as 0
        adjacency_matrix = new bool *[number_of_vertices];
        for (int i = 0; i < number_of_vertices; i++)
        {
            adjacency_matrix[i] = new bool[number_of_vertices];
            for (int j = 0; j < number_of_vertices; j++)
                adjacency_matrix[i][j] = 0;
        }
    }

    // add an edge witn vertex index provided
    void addEdge_with_vertex_index(int i, int j)
    {
        adjacency_matrix[i][j] = 1;
        adjacency_matrix[j][i] = 1;
    }

    // remove edge with vertex index provided
    void removeEdge_with_vertex_index(int i, int j)
    {
        adjacency_matrix[i][j] = 0;
        adjacency_matrix[j][i] = 0;
    }

    // print adjacency matrix
    void print_adjacency_matrix()
    {
        for (int i = 0; i < number_of_vertices; i++)
        {
            // index
            cout << i << ": ";

            // matrix content
            for (int j = 0; j < number_of_vertices; j++)
                cout << adjacency_matrix[i][j] << " ";
            cout << endl;
        }
    }
};

// Driver code
int main()
{
    Graph g(4);

    g.addEdge_with_vertex_index(0, 1);
    g.addEdge_with_vertex_index(0, 2);
    g.addEdge_with_vertex_index(1, 2);
    g.addEdge_with_vertex_index(2, 0);
    g.addEdge_with_vertex_index(2, 3);
    g.removeEdge_with_vertex_index(2, 3);

    g.print_adjacency_matrix();
}