#include <bits/stdc++.h>

using namespace std;

int main()
{
	// vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
	vector<vector<int>> costs = {{1, 2}, {3, 14}, {5, 6}, {7, 8}, {9, 10}, {11, 12}};
	auto comp = [](vector<int> &a, vector<int> &b) {
		return (a[0] - a[1]) < (b[0] - b[1]);
	};
	sort(costs.begin(), costs.end(), comp);
	int ans = 0;
	for (int i = 0; i < costs.size(); i++)
	{
		ans += (i < costs.size() / 2) ? costs[i][0] : costs[i][1];
	}
	cout<<ans;
}