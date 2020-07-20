#include<bits/stdc++.h>
using namespace std;
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    assert(1 <= t && t <= 100);
    int sum = 0;
    while (t--) {
    	int n; cin >> n;
    	assert(1 <= n && n <= 10000);
    	sum += n;
    	cout << 2 * n << '\n' << string(n, 'n') + string(n, 'o') << '\n';
    }
    assert(1 <= sum && sum <= 100000);
    return 0;
}