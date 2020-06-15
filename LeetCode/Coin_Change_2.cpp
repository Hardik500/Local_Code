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
//FIXME (Still TLE)
// int get_change_dp(vector<int> coins, int amount, int index, vector<vector<int>> &dp)
// {
//     if (amount == 0)
//     {
//         return 1;
//     }

//     if (dp[amount][index]) return dp[amount][index] - 1;

//     int result = 0;

//     for (int i = index; i < coins.size(); i++)
//     {
//         if (amount >= coins[i])
//         {
//             result += get_change_dp(coins, amount - coins[i], i, dp);
//         }
//     }

//     //save the result at this index with this amount so that in future we need not calcaulate it again
//     dp[amount][index] = result + 1;
//     return dp[amount][index] - 1;
// }

//FIXED (faster) Top-Down
//FIXME (Still TLE)
// map<string, int> hashMap;

// int get_change(int amount, vector<int> coins,int index){
//     if(amount == 0){
//         return 1;
//     }
//     else if(amount < 0){
//         return 0;
//     }
//     else if(index == coins.size() and amount > 0){
//         return 0;
//     }

//     string key = to_string(amount) + "$" + to_string(index);

//     if(hashMap.find(key) == hashMap.end()){
//         hashMap.insert(pair<string, int>(key ,get_change(amount - coins[index], coins, index) + get_change(amount, coins, index + 1)));
//     }
//     else{
//         return hashMap.find(key)->second;
//     }
//     return hashMap.find(key)->second;
// }

//Bottom up 2-D (ACCEPTED)
int get_change(int amount, vector<int> coins)
{
    int dp[coins.size() + 1][amount + 1];

    for (int i = 0; i <= coins.size(); i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1; //Number of coins with zero amount and zero coins is 1
    for (int i = 1; i <= coins.size(); i++)
    {
        dp[i][0] = 1;

        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i - 1][j]; //excluding
            if (j - coins[i - 1] >= 0) // check if amount  >= to the current i`th coin
            {
                dp[i][j] += dp[i][j - coins[i - 1]]; //including
            }
        }
    }
    return dp[coins.size()][amount];
}

//Bottom up 1-D
int get_change(int amount, vector<int> coins){
    vector<int> dp(amount + 1, 0); // default 0 initialized
    dp[0] = 1; //if nothing to change not select any coin is one way
    for (int i = 0; i < coins.size(); i++){
        for (int j = coins[i]; j <= amount; j++){ // iterate j for all coins[i]
            dp[j] = dp[j - coins[i]] + dp[j];     // selecting the coins[i - 1] for amount j
        }
    }
    return dp.back();
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int amount = 3;

    //First Solution
    // cout << get_change(coins, amount, 0);

    //Second Solution

    // int n = coins.size();
    // vector<vector<int>> dp(amount + 1, vector<int>(n + 1, 0));

    // cout<<get_change_dp(coins, amount, 0, dp);

    //Third Solution
    // cout<<get_change(amount, coins, 0);

    //Fourth Solution
    cout << get_change(amount, coins);

    //Fifth Solution (Fastest)
    cout<<get_change(amount, coins);
}

//LINK: for solution explaination
//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/discuss/677345/C++-DP-top-down-bottom-up-space-optimized-bottom-up