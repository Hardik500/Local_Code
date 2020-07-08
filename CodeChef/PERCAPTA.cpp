#include <bits/stdc++.h>

using namespace std;


//Note: A bit incomplete (Need to add condition for checking max and then traverse)

void BFS(list<int> g[], int s, int size)
{
    // Mark all the vertices as not visited
    bool visited[size];

    for (int i = 0; i < size; i++)
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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, n;
        cin >> n >> m;
        int a[n], b[n];

        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (size_t i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int adjM[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adjM[i][j] = 0;
            }
        }

        int x, y;

        for (size_t i = 0; i < m; i++)
        {
            cin >> x >> y;
            adjM[x][y] = 1;
            adjM[y][x] = 1;
        }

        int maximumF = -1;
        vector<int> pC;

        for (size_t i = 0; i < n; i++)
        {
            maximumF = max(a[i] / b[i], maximumF);
        }

        for (size_t i = 0; i < n; i++)
        {
            if (a[i] / b[i] == maximumF)
            {
                pC.push_back(i + 1);
            }
        }

        cout << pC.size() << "\n";

        for (auto x : pC)
        {
            cout << x << " ";
        }

        cout << "\n";
    }
}