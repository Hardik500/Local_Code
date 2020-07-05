#include <bits/stdc++.h>

using namespace std;

/* A Naive recursive implementation of 0-1 Knapsack problem */

// Time Complexity: O(2^n).
// As there are redundant subproblems.
// Auxiliary Space :O(1).
// As no extra data structure has been used for storing values.

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    //Base case
    if (W == 0 || n == 0)
    {
        return 0;
    }
    else if (wt[n - 1] > W)
    {
        return knapSack(W, wt, val, n - 1);
    }
    else
    {
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    }
}

// A Dynamic Programming based
// solution for 0-1 Knapsack problem

// Time Complexity: O(N*W).
// where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
// Auxiliary Space: O(N*W).
// The use of 2-D array of size ‘N*W’.

int knapSack_dp(int W, int wt[], int val[], int n)
{
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

int knapSackRec(int W, int wt[], int val[], int i, int **dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }
    if (wt[i] > W)
    {
        // Store the value of function call
        // stack in table before return
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
        return dp[i][W];
    }
    else
    {
        // Store value in a table before return 
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp), knapSackRec(W, wt, val, i - 1, dp));
        // Return value of table after storing
        return dp[i][W];
    }
}

int knapSack_mem(int W, int wt[], int val[], int n)
{
    // double pointer to declare the
    // table dynamically
    int **dp;
    dp = new int *[n];

    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }

    return knapSackRec(W, wt, val, n - 1, dp);
}

// Driver code
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack_mem(W, wt, val, n);
    return 0;
}