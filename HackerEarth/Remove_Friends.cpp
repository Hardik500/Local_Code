#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
#define fin(i, n) for(int i=1; i<=n; i++)
const int mod = 1e9+7;
#define append push_back
#define vec vector<long long int>
#define roastedcoder ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
int main()
{
    roastedcoder
    ll t; cin>>t;
    while(t--)
    {
        vec s;
        int n,k,f; cin>>n>>k>>f;
        s.append(f);
        for(int i=0; i<n-1; i++)
        {
            int a; cin>>a;
            while(k > 0 && s.size() > 0 && s.back() < a)
            {
                s.pop_back(); k--;
            }
            s.append(a);
        }
        for(int i=0; i<s.size(); i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}