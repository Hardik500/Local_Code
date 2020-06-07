#include <bits/stdc++.h>

using namespace std;

void first(){
    long long int N = 0, count = 0;
    cin>>N;
    if(N % 2 == 0){
        while(N != 1 and N%2!=1){
            N = N/2;
        }
    }
    if(N == 1){
        count = 0;
    }
    else{
        count = (N-1)/2;
    }
    cout<<count<<"\n";

}

int main(){
    int count = 0;
    cin>>count;
    while(count > 0){
        first();
        count -= 1;
    }
}