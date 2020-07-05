#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int size = 0;
        cin>>size;
        int arr[size];

        for (size_t i = 0; i < size; i++)
        {
            cin>>arr[i];
        }

        if(arr[0] < arr[size - 1]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        
    }
}