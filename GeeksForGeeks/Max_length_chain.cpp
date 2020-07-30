#include <bits/stdc++.h>

using namespace std;

struct val
{
    int first, second;
};

bool cmp(const val &a, const val &b)
{
    return a.second < b.second;
}

int maxChainLen_greedy(struct val p[], int n)
{
    sort(p, p + n, cmp);

    int count = 1, pivot = p[0].second;

    for (int i = 1; i < n; i++)
    {
        if (pivot < p[i].first)
        {
            count += 1;
            pivot = p[i].second;
        }
    }

    return count;
}

int maxChainLen_dp(struct val p[], int n)
{
    int dp[n];
    
    for(int i=0;i<n;i++)
        dp[i]=1;

    sort(p, p + n, cmp);

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (p[i].first > p[j].second and dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;

    return dp[n-1];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen_dp(p, n) << "\n";
    }
}