#include <bits/stdc++.h>

using namespace std;

void first(){
    int N = 0, K = 0;
    cin>>N>>K;
    int P[N];
    int firstSum = 0;
    int secondSum = 0;
    
    for(int i = 0; i< N; i++){
        cin>>P[i];
        firstSum += P[i];
    }
    
    for(int i = 0; i< N; i++){
        if(P[i] > K){
            secondSum += K;
        }
        else{
            secondSum += P[i];
        }
    }

    cout<<firstSum-secondSum<<"\n";
}

int main(){
    int count = 0;
    cin>>count;
    while(count > 0){
        first();
        count -= 1;
    }
}