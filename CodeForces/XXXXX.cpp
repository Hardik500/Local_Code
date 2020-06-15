#include <iostream>

using namespace std;

void first(){
    int n,x, count = 0, sum = 0;

    cin>>n>>x;

    int a[x];

    for(int i = 0;i<n; i++){
        cin>>a[i];

        if(a[i] % x == 0){
            count += 1;
        }

        sum += a[i];
    }

    if(sum % x == 0 and count == n){
        cout<<-1<<"\n";
    }
    else{
        cout<<"0"<<"\n";
    }

}

int main(){
    int count = 0;

    cin>>count;

    while(count--){
        first();
    }
}
