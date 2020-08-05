#include <bits/stdc++.h>

using namespace std;

//Greedy (Could fail when )
/*
Try this V=11, S={9,6,5,1};
Greedy Solution: 9+1+1
Dp: 6+5
*/

void solve()
{
    int n;
    cin >> n;

    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    int i = 9;

    while (i >= 0 && n != 0)
    {
        if (arr[i] > n)
            i -= 1;
        else
        {
            cout << arr[i] << " ";
            n -= arr[i];
        }
    }

    cout << "\n";
}

//Recursion Solution (Right but exponential soln)
int solut = INT_MAX;

int recursion(int coins[], int n, int value, int count = 0)
{
    if (value == 0)
        return count;

    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= value)
        {
            int temp = recursion(coins, n, value - coins[i], count + 1);

            if (count == 0)
                solut = min(solut, temp);
            else
                return temp;
        }
    }

    return count;
}

//DP soln

int change_dp(int coins[], int n, int v)
{
    int dp[v + 1];

    dp[0] = 0;

    for (int i = 1; i <= v; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= v; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                int res = dp[i - coins[j]];

                if (res != INT_MAX && res + 1 < dp[i])
                    dp[i] = res + 1;
            }
        }
    }

    return dp[v];
}

int main()
{
    int coins[] = {4, 3, 1};

    // recursion(coins, 3, 9);
    // cout << solut << "\n";

    cout << change_dp(coins, 3, 6);
}