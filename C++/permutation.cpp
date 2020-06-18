#include <bits/stdc++.h>

using namespace std;

void permute(string x, int count = 1)
{

    if (count == x.length())
    {
        cout << x << " ";
        return;
    }

    for (int i = count; i < x.length(); i++)
    {
        swap(x[count], x[i]);
        permute(x, count + 1);
        swap(x[i], x[count]);
    }
}

void permuteUsingStd(string x, int n)
{
    vector<char> permutation;
    for (int i = 0; i < n; i++)
    {
        permutation.push_back(x[i]);
    }
    do
    {
        for(auto x:permutation){
            cout<<x;
        }

        cout<<"\n";

    } while (next_permutation(permutation.begin(), permutation.end()));
}

int main()
{
    string x = "ABCD";
    int n = x.length();

    for (int i = 0; i < n; i++)
    {
        swap(x[0], x[i]);
        permute(x);
        swap(x[0], x[i]);
    }

    //OR

    permuteUsingStd(x, n);
}