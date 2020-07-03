#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, m;
    while (t--)
    {
        cin >> n >> m;

        set<int> st;
        int ans = 0, x;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            if (x != m)
                st.insert(x), ++ans;
        }

        int mex = 1;

        //Gets the minimum number which is not in the set
        while (st.count(mex))
            ++mex;

        if (mex != m)
            ans = -1;
        cout << ans << "\n";
    }

    return 0;
}