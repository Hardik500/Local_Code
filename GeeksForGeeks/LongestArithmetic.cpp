#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maximumTillNow = 0;
    int currentMaximum = 1;
    int prevDifference = 0;
    int currentDifference = 0;

    for (int i = 1; i < n; i++)
    {
        currentDifference = arr[i] - arr[i - 1];

        if (currentDifference == prevDifference)
        {
            currentMaximum += 1;

            if (currentMaximum > maximumTillNow)
                maximumTillNow = currentMaximum;
        }
        else
        {
            prevDifference = currentDifference;
            currentMaximum = 2;
        }
    }

    if (currentMaximum > maximumTillNow)
        maximumTillNow = currentMaximum;

    cout << maximumTillNow << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}