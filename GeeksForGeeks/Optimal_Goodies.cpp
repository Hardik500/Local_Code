#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k,j;
    cin>>n>>k>>j;
    
	int arr[n];

	for(int i = 0; i < n; i++)
		cin>>arr[i];

    int cost = 0;

	cost = arr[j - 1];
	k--;

	arr[j - 1] = -1;

	sort(arr, arr + n);

	int i = 0;

	while(k > 0 && i < n){
		if(arr[i] != -1){
			cost += arr[i];
			k--;
		}
		i++;
	}

	cout<<cost<<"\n";

    return 0;
}