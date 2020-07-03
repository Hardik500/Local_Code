#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;
    cin>>t;
    while(t--){
        long long int n,m,a,b,k;
        cin>>a>>b>>n>>m;
        if(a>b){k=a;a=b;b=k;}
        if(a<m){printf("No\n");continue;}
        if(a+b<n+m){printf("No\n");continue;}
        printf("Yes\n");
    }
}