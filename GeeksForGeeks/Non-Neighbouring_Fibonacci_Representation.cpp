#include <bits/stdc++.h>

using namespace std;

int nearestSmallerEqFib(int n)
{
    if (n == 0 || n == 1)
        return n;

    int a = 0, b = 1, c = 0;

    while (c <= n)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return a;
}

void find_neighobor(int n)
{
    while (n > 0)
    {
        int x = nearestSmallerEqFib(n);
        cout << x << "\n";
        n -= x;
    }
}

int main()
{
    int n;
    cin >> n;

    find_neighobor(n);
}