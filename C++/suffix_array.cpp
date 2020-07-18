#include <bits/stdc++.h>

using namespace std;

//Lexcographic Order

void generate_suffixes(string s, int size)
{
    vector<int> p(size), c(size);

    vector<pair<char, int>> a(size);
    {
        //k == 0;
        for (int i = 0; i < size; i++)
            a[i] = {s[i], i};

        sort(a.begin(), a.end());

        for (int i = 0; i < size; i++)
            p[i] = a[i].second;

        c[p[0]] = 0;

        for (int i = 1; i < size; i++)
        {
            if (a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;

    while ((1 << k) < size)
    {
        //k -> k+1
        vector<pair<pair<int, int>, int>> a(size);

        for (int i = 0; i < size; i++)
            a[i] = {{c[i], c[(i + (2 << k)) % size]}, i};

        sort(a.begin(), a.end());

        for (int i = 0; i < size; i++)
            p[i] = a[i].second;

        c[p[0]] = 0;

        for (int i = 1; i < size; i++)
        {
            if (a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }

        k++;
    }

    for (int i = 0; i < size; i++)
        cout<<p[i]<<" ";
    cout<<"\n";
}

int main()
{
    string s;
    int sizeOfString;
    cin >> s;
    s += "$";
    sizeOfString = s.size();
    generate_suffixes(s, sizeOfString);
}