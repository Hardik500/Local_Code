#include <bits/stdc++.h>

using namespace std;

//Brute force
// void solve(vector<int> arr, int sum)
// {
//     int n = arr.size();
//     int count = 0;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] + arr[j] == sum)
//             {
//                 count += 1;
//             }
//         }
//     }

//     cout << count << "\n";
// }

//O(n) complexity
void solve()
{
    int n, sum, temp;
    cin >> n >> sum;

    vector<int> arr;

    for(int i = 0; i < n; i++){
        cin>>temp;
        arr.push_back(temp);
    }

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        count += m[sum - arr[i]];

        if (sum - arr[i] == arr[i])
            count--;
    }

    cout << count / 2 << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}