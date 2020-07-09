#include <bits/stdc++.h>

using namespace std;

#define int long long

int getSum(int n)
{
    int sum;

    for (sum = 0; n > 0; sum += n % 10, n /= 10);

    return sum;
}

void solve()
{
    int n, x, y, sum = 0, morty = 0, chef = 0, p = 0, q = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin>>x>>y;

        p = getSum(x);
        q = getSum(y);

        if(p > q){
            morty += 1;
        }
        else if(q > p){
            chef += 1;
        }
        else{
            morty += 1;
            chef += 1;
        }
    }

    if(morty > chef)
        cout<<0<<" "<<morty<<"\n";
    else if(morty < chef)
        cout<<1<<" "<<chef<<"\n";
    else
        cout<<2<<" "<<morty<<"\n";
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}