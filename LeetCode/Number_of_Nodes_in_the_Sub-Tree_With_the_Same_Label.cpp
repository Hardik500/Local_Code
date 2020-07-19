#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> adj;
    string l;
    vector<int> ans;
    int c[26] = {};

    void dfs(int u = 0, int p = -1)
    {
        int lc = c[l[u] - 'a']++;

        for (int v : adj[u])
            if (v ^ p)
                dfs(v, u);

        ans[u] = c[l[u] - 'a'] - lc;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> edges, string labels)
    {
        adj = vector<vector<int>>(n);

        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        }

        l = labels;

        ans = vector<int>(n);

        dfs();

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> q;
    q = s.countSubTrees(4, {{0,1},{1,2},{0,3}}, "bbbb");
    for (auto x : q)
    {
        cout << x << " ";
    }
}