#include <bits/stdc++.h>

using namespace std;


//Lexcographic Order

//Naive Method
void generate_suffixes(string s, int size)
{
    vector<string> suffixes;

    int i = size - 1;

    for (int len = 0; len < size; len++)
    {
        suffixes.push_back(s.substr(len, i + 1));
        i += 1;
    }

    // for (auto x : suffixes)
    // {
    //     cout << x << "\n";
    // }

    sort(suffixes.begin(), suffixes.end());

    for (auto x : suffixes)
    {
        cout << x << "\n";
    }

}

int main()
{
    generate_suffixes("ababba", 6);
}