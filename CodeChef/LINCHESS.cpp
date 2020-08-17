#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;

    cin >> n >> k;

    int arr[n];

    int sum = INT_MAX;

    int minimum = INT_MAX;

    int temp = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (k % arr[i] == 0){
            temp = k / arr[i] - 1;

            if(temp < sum){
                sum = temp;
                minimum = arr[i];
            }
        }
    }

    if (sum == INT_MAX)
        cout << -1 << "\n";
    else
        cout << minimum << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}