#include <bits/stdc++.h>

using namespace std;

bool prime(int x)
{
    for (int j = 2; j * j < x; j++)
    {
        if (x % j == 0)
            return false;
    }

    return true;
}

int main()
{
    int p1, p2;
    cin >> p1 >> p2;
    bool flag = true;
    vector<string> firstPrimeList;

    for (int i = p1; i <= p2; i++)
    {
        if (prime(i))
            firstPrimeList.push_back(to_string(i));
    }

    vector<long> combinationOfPrimes;

    for (int i = 0; i < firstPrimeList.size(); i++)
    {
        for (int j = 0; j < firstPrimeList.size(); j++)
        {
            if (i != j)
            {
                string tmp = firstPrimeList[i] + firstPrimeList[j];
                combinationOfPrimes.push_back(stoi(tmp));
            }
        }
    }

    vector<int> secondPrimeList;

    for (auto x : combinationOfPrimes)
    {
        if (prime(x))
            secondPrimeList.push_back(x);
    }

    long minimum = secondPrimeList[0];
    long maximum = secondPrimeList[secondPrimeList.size() - 1];

    long count = 0, a = minimum, b = maximum, c;

    for (long long i = 3; i <= (long long)(secondPrimeList.size()); i++)
    {
        c = a + b;
        a = b;
        b = c;
        count += 1;
    }

    cout << c << "\n";
}