#include <bits/stdc++.h>

using namespace std;

const int V = 5;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int node, int sibling)
{
    adj[node].push_back(sibling);
    adj[sibling].push_back(node);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int nodes)
{
    for (int v = 0; v < nodes; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
            cout << " -> " << x;
        printf("\n");
    }
}

void addEdgeMatrix(int adjM[][V], int node, int sibling)
{
    adjM[node][sibling] = 1;
    adjM[sibling][node] = 1;
}

void printGraphMatrix(int adjM[][V], int nodes)
{
    for (int v = 0; v < nodes; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (int i = 0; i < nodes; i++)
        {
            if (adjM[v][i] == 1)
                cout << " -> " << i;
        }
        printf("\n");
    }
}

int main()
{

    //Using adjacency list
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // printGraph(adj, V);

    //Using adjacency matrix
    int adjM[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adjM[i][j] = 0;
        }
    }

    addEdgeMatrix(adjM, 0, 1);
    addEdgeMatrix(adjM, 0, 4);
    addEdgeMatrix(adjM, 1, 2);
    addEdgeMatrix(adjM, 1, 3);
    addEdgeMatrix(adjM, 1, 4);
    addEdgeMatrix(adjM, 2, 3);
    addEdgeMatrix(adjM, 3, 4);

    printGraphMatrix(adjM, V);

    return 0;
}