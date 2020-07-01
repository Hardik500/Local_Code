#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;
    cin>>t;
    while(t--){
        int n = 0;
        cin>>n;
        if(n%2==0){
            cout<<n/2<<"\n";
        }
        else{
            cout<<(n + 1)/2<<"\n";
        }
    }
}