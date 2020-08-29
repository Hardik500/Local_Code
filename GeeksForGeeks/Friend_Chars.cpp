#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int sumPairs(vector<long long int> vec, int n)
{
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
        sum += i * vec[i] - (n - 1 - i) * vec[i];
    return sum;
}

int main()
{
    string x;
    cin >> x;

    int sizeOfString = x.size();

    int distance = 0;

    vector<long long int> z[26];

    for (int i = 0; i < sizeOfString; i++)
        z[x[i] - 'a'].push_back(i);

    for(int i = 0; i < 26; i++)
    {
        int sizeOfVector = z[i].size();

        if (sizeOfVector > 1)
            distance += sumPairs(z[i], sizeOfVector);
    }

    cout << distance << "\n";

    return 0;
}
