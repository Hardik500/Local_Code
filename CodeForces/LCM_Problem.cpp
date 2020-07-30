#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;

    if(x * 2 <= y){
        cout<<x<<" "<<x*2<<"\n";
    }
    else{
        cout << -1 << " " << -1 << "\n";
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}