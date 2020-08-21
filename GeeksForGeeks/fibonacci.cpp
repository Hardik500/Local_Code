#include <bits/stdc++.h>

using namespace std;

int fibo_rec(int n)
{
    if (n <= 1)
        return n;
    else
        return fibo_rec(n - 1) + fibo_rec(n - 2);
}

int fibo_iter(int n)
{
    int a = 0;
    int b = 1;
    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }

    return sum;
}

unordered_map<int, int> dp;

int fibo_rec_dp(int n)
{
    if (n <= 1)
        return n;
    else if (dp.find(n) != dp.end())
        return dp[n];
    else
    {
        dp[n] = fibo_rec(n - 1) + fibo_rec(n - 2);
        return dp[n];
    }
}

int fibo_iter_dp(int n)
{
    int f[n + 2];
    int i;

    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    return f[n];
}

int fib_Binets_formula(int n)
{
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}

int main()
{
    int n = 10;
    cout << fib_Binets_formula(n);
}