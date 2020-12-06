#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void dfs(int u, bool visited[], int parent[], int id[], int low[], vector<vector<int>> &result, vector<vector<int>> &adj)
    {
        static int time = 0;
        visited[u] = true;
        id[u] = low[u] = time++;

        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = *i;
            if (v == parent[u])
                continue;

            if (!visited[v])
            {
                parent[v] = u;
                dfs(v, visited, parent, id, low, result, adj);
                low[u] = min(low[u], low[v]);
                if (id[u] < low[v])
                    result.push_back({u, v});
            }
            else
                low[u] = min(low[u], id[v]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> result;
        vector<vector<int>> adj(n);

        bool *visited = new bool[n];
        int *parent = new int[n];
        int *id = new int[n];
        int *low = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            visited[i] = false;
        }

        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        dfs(0, visited, parent, id, low, result, adj);

        return result;
    }
};

int main()
{

    Solution s;

    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    vector<vector<int>> result = s.criticalConnections(n, connections);

    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
}