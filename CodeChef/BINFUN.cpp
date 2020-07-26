#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define pb push_back
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define endl "\n"
#define pii pair<int, int>
#define mii map<int, int>
#define int long long int
#define fbo find_by_order
#define ook order_of_key
#define in insert
#define F first
#define S second
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define print(a)                   \
        for (auto ws : a)          \
                cout << ws << " "; \
        cout << endl
#define print1(a, b)                   \
        for (int ws = 0; ws < b; ws++) \
        {                              \
                cout << a[ws] << " ";  \
        }                              \
        cout << endl
#define all(a) a.begin(), a.end()
#define si set<int>
#define print2(a)                                           \
        for (auto ws : a)                                   \
                cout << "(" << ws.F << "," << ws.S << ") "; \
        cout << endl

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
        cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
        const char *comma = strchr(names + 1, ',');
        cout.write(names, comma - names) << " : " << arg1 << " | ";
        __f(comma + 1, args...);
}
int binaryToDecimal(string n)
{
        string num = n;
        int dec_value = 0;

        // Initializing base value to 1, i.e 2^0
        int base = 1;

        int len = num.length();
        for (int i = len - 1; i >= 0; i--)
        {
                if (num[i] == '1')
                        dec_value += base;
                base = base * 2;
        }

        return dec_value;
}
void solve()
{
        int n;
        cin >> n;
        vi a(n);
        int mxi = 0;
        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
                mxi = max(a[i], mxi);
        }
        std::vector<string> v;
        string st = bitset<32>(mxi).to_string();
        while (st.size() > 0 && st[0] == '0')
        {
                st.erase(0, 1);
        }
        for (int i = 0; i < n; ++i)
        {
                string str = bitset<32>(a[i]).to_string();
                while (str.size() > 0 && str[0] == '0')
                {
                        str.erase(0, 1);
                }
                v.pb(str);
        }
        int mx = 0;
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n && n < 1000; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        string s = v[i] + v[j];
                        string t = v[j] + v[i];
                        int s1 = binaryToDecimal(s);
                        int t1 = binaryToDecimal(t);
                        if (s1 - t1 > mx)
                        {
                                mx = s1 - t1;
                        }
                }
        }
        for (int i = 0; i < n; i++)
        {

                string s = st + v[i];
                string t = v[i] + st;
                int s1 = binaryToDecimal(s);
                int t1 = binaryToDecimal(t);
                if (s1 - t1 > mx)
                {
                        mx = s1 - t1;
                }
        }
        cout << mx << endl;
}
int32_t main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout << setprecision(9) << fixed;
        int t = 1;
        cin >> t;
        while (t--)
        {
                solve();
        }
        return 0;
}