#include <bits/stdc++.h>

using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

int countUnsetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += !(n & 1);
        n = n >> 1;
    }
    return count;
}

int main()
{
    int n = 1;
    cout << countSetBits(n) + countUnsetBits(n)<< "\n";
}