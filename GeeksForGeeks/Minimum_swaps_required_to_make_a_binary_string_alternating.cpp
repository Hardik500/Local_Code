#include <bits/stdc++.h>

using namespace std;

void solve(string x)
{
    vector<int> odd_0, even_0, odd_1, even_1;

    for (int i = 0; i < x.size(); i++)
    {
        if (i % 2)
        {
            if (x[i] == '0')
                odd_0.push_back(i);
            else
                odd_1.push_back(i);
        }
        else
        {
            if (x[i] == '0')
                even_0.push_back(i);
            else
                even_1.push_back(i);
        }
    }

    int noOfSwaps = min(odd_0.size(), odd_1.size());

    cout<<noOfSwaps<<"\n";
}

int main()
{
    string x;
    cin >> x;

    solve(x);
}