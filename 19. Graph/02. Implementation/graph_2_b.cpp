/*
    https://bit.ly/3It2i4m

    ================== Adjacency Matrix Representation ==================

    vertex_list is a vector of strings
        - Assuming a node contains a string value
        - Can contain any data type i.e. not limited to string, int etc

    adjacency_matrix is a 2-dimensional matrix that contains edges
        - A value in adj_mat[i][j] is 1 if there is an edge from i to j
        - Otherwise adj_mat[i][j] contains 0
        - Adjacency matrix representations is suitable for dense graph
        - A dense graph is a graph where |E| is close to maximum
        - If we want to use weighted graph then set adj_mat[i][j] = weight


    Space Complexity:
        O(|v| + (|v| * |v|)) => (num_of_vertex in vertex_list + size of adj_mat)

    Time Complexity:
        Find adjacent nodes:
            if vertex index is given: O(|v|) simply scan adj_mat for ith row
            if vertex name is given: O(|v| + |v|) scan in vertex_list + scan in adj_mat for ith row
        Check if given nodes are connected:
            if index is gievn: O(1)
            if vertex name is given: O(|v|) scan in vertex_list + check adj_mat[i][j]

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

    // NOTE: we don't need vertex list if we plan to denote vertex by index only
    vector<string> vertex_list;

    // declare adjacency matrix
    vector<vector<bool>> adjacency_matrix;

public:
    // graph constructor
    Graph(int number_of_vertices)
    {
        // receive total number of vertices from user
        this->number_of_vertices = number_of_vertices;

        // initializing adjacency matrix with accurate size and each cell value as 0
        adjacency_matrix.resize(number_of_vertices, vector<bool>(number_of_vertices, 0));
    }

    // add a vertex
    void addVertex_name(string vertexName)
    {
        // add vertex name
        vertex_list.push_back(vertexName);
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

    // add an edge with vertex name provided
    void addEdge_with_vertex_name(string origin_vertex, string destination_vertex)
    {
        // find given vertices' indices in vertex_list
        int origin_index = -1, destination_index = -1;
        for (int i = 0; i < vertex_list.size(); i++)
        {
            if (vertex_list[i] == origin_vertex)
                origin_index = i;
            if (vertex_list[i] == destination_vertex)
                destination_index = i;
        }

        // ensure given vertices exist
        if (origin_index == -1 or destination_index == -1)
            return;

        // add edge logic
        adjacency_matrix[origin_index][destination_index] = 1;
        adjacency_matrix[destination_index][origin_index] = 1;
    }

    // remove edge with vertex name provided
    void removeEdge_with_vertex_name(string origin_vertex, string destination_vertex)
    {
        // find given vertices' indices in vertex_list
        int origin_index = -1, destination_index = -1;
        for (int i = 0; i < vertex_list.size(); i++)
        {
            if (vertex_list[i] == origin_vertex)
                origin_index = i;
            if (vertex_list[i] == destination_vertex)
                destination_index = i;
        }

        // ensure given vertices exist
        if (origin_index == -1 or destination_index == -1)
            return;

        // remove edge logic
        adjacency_matrix[origin_index][destination_index] = 0;
        adjacency_matrix[destination_index][origin_index] = 0;
    }

    // print vertex list
    void print_vertex_list()
    {
        for (int i = 0; i < vertex_list.size(); i++)
            cout << vertex_list[i] << " ";
        cout << endl;
    }

    // print adjacency matrix
    void print_adjacency_matrix()
    {
        for (int i = 0; i < adjacency_matrix.size(); i++)
        {
            // index
            cout << i << ": ";

            // matrix content
            for (int j = 0; j < adjacency_matrix[i].size(); j++)
                cout << adjacency_matrix[i][j] << " ";
            cout << endl;
        }
    }
};

// Driver code
int main()
{
    Graph g(4);

    /* ========= using indices ======== */
    // g.addEdge_with_vertex_index(0, 1);
    // g.addEdge_with_vertex_index(0, 2);
    // g.addEdge_with_vertex_index(1, 2);
    // g.addEdge_with_vertex_index(2, 0);
    // g.addEdge_with_vertex_index(2, 3);
    // g.removeEdge_with_vertex_index(2, 3);

    // g.print_adjacency_matrix();

    /* ========= using names ======== */
    g.addVertex_name("A");
    g.addVertex_name("B");
    g.addVertex_name("C");
    g.addVertex_name("D");

    g.print_vertex_list();

    g.addEdge_with_vertex_name("A", "B");
    g.addEdge_with_vertex_name("A", "C");
    g.addEdge_with_vertex_name("B", "C");
    g.addEdge_with_vertex_name("C", "A");
    g.addEdge_with_vertex_name("C", "D");
    g.removeEdge_with_vertex_name("C", "D");

    g.print_adjacency_matrix();
}