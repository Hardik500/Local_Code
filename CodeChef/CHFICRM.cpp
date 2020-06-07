#include <bits/stdc++.h>

using namespace std;

void first(){
    int N = 0;
    cin>>N;
    bool unable = false;
    int P[N], sum = 0;
    
    for(int i = 0; i< N; i++){
        cin>>P[i];
        if(P[i] == 5){
            sum += P[i];
        }
        else{
            if(P[i] - sum == 5){
                sum = 5;
            }
            else if(sum - P[i] >= 5){
                sum -= P[i];
            }
            else{
                unable = true;
                cout<<"NO";
                break;
            }
        }
    }
    if(not unable){
        cout<<"YES";
    }
    cout<<"\n";

}

int main(){
    int count = 0;
    cin>>count;
    while(count > 0){
        first();
        count -= 1;
    }
}