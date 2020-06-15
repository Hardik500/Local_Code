#include <bits/stdc++.h>

using namespace std;

void first()
{
    int n, x, count = 0, sum = 0, left = 0, right = 0, ans = 0;

    cin >> n >> x;

    int arr[n];
    right = n - 1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];

        if (arr[i] % x == 0)
        {
            count += 1;
        }
    }

    if (sum % x == 0 and count == n)
        ans = -1;
    else
    {
        while (left < right + 1)
        {
            sum -= arr[left];
            left += 1;
            if (sum % x)
            {
                ans = max(ans, left);
            }
        }

        left = 0;
        sum = 0;

        while (left < right + 1)
        {
            sum -= arr[right];
            if (sum % x)
            {
                ans = max(ans, n - right);
            }
            right -= 1;
        }
    }

    cout << ans << "\n";
}

int main()
{
    int count = 0;
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> count;

    while (count--)
        first();
}