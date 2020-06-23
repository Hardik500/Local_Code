#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c, index;
        string v;
        cin >> c >> v;

        for (int i = c - 1; i >= 0; i--)
        {
            if (v[i] == '0')
            {
                index = i;
                break;
            }
        }

        int done = 0;

        for (int i = 0; i <= index; i++)
        {
            if (v[i] == '1')
            {
                done = 1;
                break;
            }
        }

        if (done)
        {
            for (int i = index; i < c; i++)
            {
                cout << v[i];
            }
            cout << "\n";
        }
        else
        {
            cout << v << "\n";
        }
    }
}