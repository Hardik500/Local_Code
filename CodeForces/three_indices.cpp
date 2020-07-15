#include <bits/stdc++.h>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin>>n;

    int arr[n];

    for (size_t i = 0; i < n; i++)
        cin>>arr[i];

    for (size_t i = 1; i < n - 1; i++){
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            cout<<"YES\n";
            cout<<i<<" "<<i + 1<<" "<<i+2<<"\n";
            return;

        }
    }

    cout<<"NO\n";
    
}

int main()
{
    IOS;
    int t;
    cin>>t;

    while(t--)
        solve();
}