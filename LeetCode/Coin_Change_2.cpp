#include <bits/stdc++.h>

using namespace std;

//FIXME (Time limit exceeded)
// int get_change(int arr[], int sum = 5, int index = 0)
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

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    // cout << get_change(arr, 5, 0);

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++)
        for (int j = coins[i]; j <= amount; j++)
            dp[j] = dp[j - coins[i]] + dp[j];
    cout<<dp.back();
}