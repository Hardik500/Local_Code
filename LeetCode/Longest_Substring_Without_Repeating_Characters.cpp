#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    //O(2n)
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;

        int maximum = 0;

        unordered_map<char, int> x;

        while (i < s.size() && j < s.size())
        {
            if (x.find(s[j]) == x.end() || x[s[j]] == 0)
            {
                x[s[j++]] += 1;
                maximum = max(maximum, j - i);
            }
            else
                x[s[i++]] -= 1;
        }

        return maximum;
    }
};

int main()
{
    Solution s;

    cout << s.lengthOfLongestSubstring("pwwkew") << "\n";
}