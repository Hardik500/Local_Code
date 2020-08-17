#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x,y;
    cin>>x>>y;

    while(x > 0 && y > 0){
        x -= y;
        y/=2;
    }

    if(x <= 0)
        cout<<1<<"\n";
    else
        cout<<0<<"\n";
}

int main(){
    int t;
    cin.tie();
    cout.tie();
    cin>>t;

    while(t--)
        solve();
}