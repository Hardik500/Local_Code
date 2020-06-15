#include <bits/stdc++.h>

using namespace std;

unordered_set<string> st;

void subSets(string str, int n, int index = -1, string curr = "")
{
    if (index == n)
    {
        return;
    }

    cout << curr << "\n";

    for (int i = index + 1; i < n; i++)
    {
        curr += str[i];
        subSets(str, n, i, curr);
        curr = curr.erase(curr.size() - 1);
    }

    return;
}

int main()
{
    string str = "ABC";
    subSets(str, str.length());
}