#include <bits/stdc++.h>

using namespace std;

int gcdF(int a, int b){
    if(b == 0){
        return a;
    }

    return gcdF(b, a%b);
}

void first(){
    int n, gcd;
    cin>>n;

    if(n >= 4){
            if(n % 2){
                gcd = gcdF((n-1)/2,( n - 1));
            }
            else{
                gcd = gcdF(n/2, n);
            }
    }
    else{
        gcd = 1;
    }

    cout<<gcd<<"\n";
}

int main(){
    int count = 0;
    cin>>count;
    while(count--){
        first();
    }
}