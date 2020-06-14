#include <bits/stdc++.h>

using namespace std;

//FIXME (Time limit exceeded)
// int get_change(vector<int> arr, int sum = 5, int index = 0)
// {

//     if (sum == 0)
//     {
//         return 1;
//     }
//     else if (sum < 0)
//     {
//         return 0;
//     }
//     int result = 0;

//     for (int i = index; i < 3; i++)
//     {
//         if (sum >= arr[i])
//         {
//             result += get_change(arr, sum - arr[i], i);
//         }
//     }

//     return result;
// }

//FIXED (faster) Top-Down
int get_change_dp(vector<int> coins, int amount, int index, vector<vector<int>> &dp)
{
    if (amount == 0)
    {
        return 1;
    }

    if (dp[amount][index]) return dp[amount][index] - 1;

    int result = 0;

    for (int i = index; i < 3; i++)
    {
        if (amount >= coins[i])
        {
            result += get_change_dp(coins, amount - coins[i], i, dp);
        }
    }

    //save the result at this index with this amount so that in future we need not calcaulate it again
    dp[amount][index] = result + 1;
    return dp[amount][index] - 1;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    // cout << get_change(coins, 5, 0);

    int n = coins.size();
    vector<vector<int>> dp(amount + 1, vector<int>(n + 1, 0));

    cout<<get_change_dp(coins, 5, 0, dp);

    //Fast
    // vector<int> dp(amount + 1, 0);
    // dp[0] = 1;
    // for (int i = 0; i < coins.size(); i++)
    //     for (int j = coins[i]; j <= amount; j++)
    //         dp[j] = dp[j - coins[i]] + dp[j];
    // cout << dp.back();
}