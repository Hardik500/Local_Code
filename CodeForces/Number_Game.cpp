#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool findWinner(int n)
{
    if (n == 1)
    {
        return false;
    }
    if (n & 1)
    {
        return true;
    }
    int k = 0;
    while (n % 2 == 0)
    {
        k++;
        n /= 2;
    }
    if (n == 1)
    {
        return k == 1;
    }
    return k != 1 || !isPrime(n);
}

int main()
{
    int count = 0, n = 0;
    cin >> count;
    while (count--)
    {
        cin >> n;
        if (findWinner(n))
        {
            cout << "Ashishgup\n";
        }
        else
        {
            cout << "FastestFinger\n";
        }
    }
}