#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> alphabet = {"a", "b", "c", "ch", "d", "dd", "e", "f", "ff", "g", "ng", "h", "i", "l", "ll", "m", "n", "o", "p", "ph", "r", "rh", "s", "t", "th", "u", "w", "y"};
    vector<string> input = {"dd r", "n a h", "d e a", "dd", "ng a h"};
    vector<string> output;

    unordered_map<string, int> dict;

    vector<vector<int>> v(input.size());

    for (int i = 0; i < alphabet.size(); i++)
        dict[alphabet[i]] = i;

    for (int i = 0; i < input.size(); i++)
    {
        istringstream ss(input[i]);
        string cur;

        while (ss >> cur)
            v[i].push_back(dict[cur]);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        output.push_back("");
        for (auto &x : v[i])
            output[i] += alphabet[x];
    }

    for (auto &x : output)
        cout << x << ' ';
}