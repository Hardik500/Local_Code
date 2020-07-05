#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, pos = 0, neg = 0, prev = 0, zeros = 0;

        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr[i] = x;
        }

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] = abs(arr[i]);
            }
            else
            {
                arr[i] = -1 * abs(arr[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }
}