#include <bits/stdc++.h>

using namespace std;

unsigned int isPowerOfTwo(unsigned int n){
    int count = 0;

    while(n){
        count += n & 1;
        n = n>>1;
    }

    cout<<count<<"\n";

    return count;
}

int main(){
    int n = -2147483648;
    if(isPowerOfTwo(n) == 1){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}