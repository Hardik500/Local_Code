#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main()
{

    long long int n, k;
    cin >> n >> k;
    long long int ctr = 0;
    while (n % 2 == 0)
    {
        ctr++;
        n /= 2;
    }
    k -= ctr;
    ctr = 0;
    long long int sum = 0;
    long long int mul = 1;
    for (int i = 1; i <= 25; i++)
    {
        sum += mul;
        mul *= 16;
    }
    while (sum % 2 == 0)
    {
        ctr++;
        sum /= 2;
    }
    long long int count = k / (4 + ctr);
    k = k % 4;
    if (k != 0)
        count++;
    cout << count;
    return 0;
}