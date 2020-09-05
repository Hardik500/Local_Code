#include <bits/stdc++.h>

using namespace std;

long long int result[1000000] = {0};

void factorial(long long int n){
	if(n >= 0){
		result[0] = 1;

		for(long long int i = 1; i <= n; i++){
			result[i] = i * result[i - 1];
		}
	}
}

void solve(){
	long long int n, k, m;
	cin>>n>>k>>m;

	long long int S = m;
	long long int N = n - k + 1;

	factorial(S + N - 1);

	long long int numerator = result[S + N - 1];
	long long int denominator = result[S] * result[N - 1];

	double result = fmod(numerator/denominator, 10e9 + 7);

	cout<<result<<"\n";
}

int main(){
	int t;
	cin>>t;

	while(t--)
		solve();
}