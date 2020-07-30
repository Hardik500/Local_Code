#include <bits/stdc++.h>

using namespace std;

int rec(int index, int k, int z, vector<int> x, bool left = false, int sum = 0, int count = 0)
{
    int p = 0, q = 0;

    if (index == k + 1)
    {
        return sum;
    }
    else if(count == k + 1){
        return sum;
    }
    else
    {
        sum += x[index];

        if (x[index - 1] > x[index + 1] && !left && z > 0)
            p = max(rec(index - 1, k, z - 1, x, true, sum, count + 1), rec(index + 1, k, z, x, false, sum, count + 1));
        else
            q = rec(index + 1, k, z, x, false, sum, count + 1);

        sum = max(p, q);
    }
    return sum;
}

void solve()
{
    int n, k, z;
    cin >> n >> k >> z;

    vector<int> vec(n);

    for (int &x : vec)
    {
        cin >> x;
    }

    cout << rec(0, k, z, vec) << "\n";
}

int main()
{
    int t;
    cin.tie(0);
    cout.tie(0);
    cin >> t;

    while (t--)
        solve();
}