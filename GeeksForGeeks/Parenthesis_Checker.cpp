#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    unordered_map<char, char> x;

    x.insert(make_pair('{', '}'));
    x.insert(make_pair('}', '{'));
    x.insert(make_pair('[', ']'));
    x.insert(make_pair(']', '['));
    x.insert(make_pair('(', ')'));
    x.insert(make_pair(')', '('));

    while (t--)
    {
        string y;
        cin >> y;

        stack<char> s;

        for (int i = 0; i < y.size(); i++)
        {
            if (s.size() && s.top() == x[y[i]])
                s.pop();
            else
                s.push(y[i]);
        }

        if (s.size())
            cout << "not balanced\n";
        else
            cout << "balanced\n";
    }
    return 0;
}