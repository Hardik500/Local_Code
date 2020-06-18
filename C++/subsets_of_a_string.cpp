#include <bits/stdc++.h>

using namespace std;

unordered_set<string> st;

//Recusrsive approact
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

//Bits approact
void subSetsB(string str, int n)
{
    for (int b = 0; b < (1 << n); b++)
    {
        vector<char> subset;
        for (int i = 0; i < n; i++)
        {
            if (b & (1 << i))
                subset.push_back(str[i]);
        }

        for (auto x : subset)
        {
            cout << x << " ";
        }

        cout << "\n";
    }
}

int main()
{
    string str = "ABC";
    int n = str.length();
    // subSets(str, n);
    subsetA(str, 0, n);
    // subSetsB(str, n);
}