#include <bits/stdc++.h>

using namespace std;

void first(){
	int N = 0;
	cin>>N;
	int M = 1, X = 0;
	
	for(int j=1;j<=N;j++){
		if(j%2!=0){
			for(int i=M;i<=N*j;i++){
				cout<<i<<" ";
				if(i%N == 0){
					cout<<"\n";
				}
                M = i;
                X = i;
			}
		}
		else{
            M = N*j + 1;
			for(int i=N*j;i>X;i--){
				cout<<i<<" ";
				if((i - 1) == X){
					cout<<"\n";
				}
			}
		}
	}
}

int main(){
	int count = 0;
	cin>>count;
	
	while(count -- > 0){
		first();
	}
}
