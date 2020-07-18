#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

void solve()
{
    long long int n, p;

    cin >> n;

    unordered_map<int, int> x;

    vector<int> z;

    for (int i = 0; i < n * 2; i++)
    {
        cin >> p;
        
        x[p] += 1;

        if(x[p] == 1){
            z.push_back(p);
        }
    }


    for (auto m : z)
        cout << m << " ";

    cout << "\n";
}

int main()
{
    IOS;
    int t = 0;
    cin >> t;

    while (t--)
        solve();
}