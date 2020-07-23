#include <bits/stdc++.h>

using namespace std;

void brute_force(string s, int n)
{
    string maximumPalindrome = "";

    for (int i = 0; i < s.size(); i++)
        for (int len = i; len < n; len++)
        {
            string y = s.substr(i, len);
            string x = y;
            reverse(x.begin(), x.end());
            if (y == x)
                if (y.size() > maximumPalindrome.size())
                    maximumPalindrome = y;
        }

    cout << maximumPalindrome << "\n";
}

//Returns the length of max substring
int rec(string s, int i, int j){
    if(i == j)
        return 1;
    if (s[i] == s[j] && i + 1 == j) 
        return 2;
    if(s[i] == s[j])
        return rec(s, i + 1, j - 1) + 2;

    return max(rec(s, i, j - 1), rec(s, i + 1, j));
}

void dp(string s, int size)
{
    bool table[size][size];

    memset(table, 0, sizeof(table));

    //Length 1 substrs
    for (int i = 0; i < size; i++)
        table[i][i] = true;

    int maxLength = 1;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < size; ++i)
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2. 
    // k is length of substring 
    for (int k = 2; k <= size; k++)
    {
        // Fix the starting index 
        for (int i = 0; i < size - k + 1; i++)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i + 1][j - 1] && s[i] == s[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    cout<<s.substr(start, maxLength);
}

int main()
{
    string s = "geekee";
    // dp(s, s.size());
    cout<<rec(s, 0, s.size());
}