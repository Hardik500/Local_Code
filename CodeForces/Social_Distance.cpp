#include <bits/stdc++.h>

using namespace std;

void first()
{

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set <int> q;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') q.insert(i);
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        auto it = q.lower_bound(i - k);
        if (it == q.end() || *it > i + k) {
          s[i] = '1';
          ans++;
          q.insert(i);
        }
      }
    }
    cout << ans << '\n';
}

int main()
{
    int count = 0;
    cin >> count;

    while (count--)
    {
        first();
    }
}