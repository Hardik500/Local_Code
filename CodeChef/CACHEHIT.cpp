#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, b, m, z;
        cin >> n >> b >> m;
        vector<int> x;
        for (int i = 0; i < m; i++)
        {
            cin >> z;
            x.push_back(z);
        }

        int prev = -1, count = 0;

        for (auto p : x)
        {
            if ((p / b) != prev)
            {
                prev = p / b;
                count += 1;
            }
        }

        cout << count << "\n";
    }
}