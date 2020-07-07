#include <bits/stdc++.h>

using namespace std;

const int V = 4;

// A utility function to add an edge in an
// undirected graph.
void addEdge(list<int> g[], int node, int sibling)
{
    g[node].push_back(sibling);
}

void BFS(list<int> g[], int s)
{
    // Mark all the vertices as not visited
    bool visited[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;

    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while (queue.empty() == false)
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = g[s].begin(); i != g[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    //Using adjacency list
    list<int> g[V];
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);
    addEdge(g, 3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";

    BFS(g, 2);

    return 0;
}