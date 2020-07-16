#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string x, c;

    cin >> x;

    int p = 0,r = 0,s = 0;

    char m;

    for (int i = 0; i < x.size(); i++)
    {
        if(x[i] == 'R'){
            r += 1;
        }
        else if(x[i] == 'P'){
            p += 1;
        }
        else if(x[i] == 'S'){
            s += 1;
        }
    }

    int maximum = max(r, max(s, p));

    if(r == maximum){
        m = 'P';
    }
    else if(s == maximum){
        m = 'R';
    }
    else if(p == maximum){
        m = 'S';
    }

    for (int i = 0; i < x.size(); i++){
        c += m;
    }

    cout<<c<<"\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}