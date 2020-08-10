#include <bits/stdc++.h>

using namespace std;

int pairs_count(int arr[], int n, int sum)
{
    int i = 0, j = n - 1, c = 0;

    while (i < j)
    {
        int x = arr[i] + arr[j];

        if (x == sum)
        {
            c++;
            i++;
            j--;
        }
        else if (x < sum)
            i++;
        else if (x > sum)
            j--;
    }

    return c;
}

void solve()
{
    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int f[101] = {0};

    for (int i = 0; i < 101; i++)
        f[i] = pairs_count(a, n, i);

    int ans = 0;

    for (int i = 0; i < 101; i++)
        ans = max(f[i], ans);

    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}