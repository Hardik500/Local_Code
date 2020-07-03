#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n = 0, S = 0, prev = 0, sum = 0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>S;
            if(S!=0 and S!=prev){
                if(prev > S){
                    sum += prev - S - 1;
                }
                else{
                    sum += S - prev - 1;
                }
            }
            prev = S;
        }

        cout<<sum<<"\n";
    }
}