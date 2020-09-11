#include <bits/stdc++.h>

using namespace std;

int ans = 1;

int guess(int n)
{
    if (n == ans)
        return 0;
    else if (n > ans)
        return -1;
    else
        return 1;
}

int guessNumber(int n)
{
    long long int q = n;
    long long int result = guess(q);

    long long int greaterThan = 1;
    long long int smallerThan = n;

    while (result != 0)
    {
        q = (greaterThan + smallerThan) / 2;
        result = guess(q);

        if (result == 1)
            greaterThan = q;
        else
            smallerThan = q;
    }

    return q;
}

int main()
{
    cout << guessNumber(3);
}