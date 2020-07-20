#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> maxNumOfSubstrings(string s)
    {
        vector<int> c(26);
        vector<string> ans;

        char prev;

        for (int i = 0; i < s.size(); i++)
        {
            if (c[s[i] - 'a'] and prev == s[i] and c[s[i] - 'a'] != -1)
                c[s[i] - 'a'] += 1;
            else if(c[s[i]  - 'a'] == 0)
                c[s[i] - 'a'] = 1;
            else
                c[s[i] - 'a'] = -1;
            
            prev = s[i];
        }

        string z;
        int i = 0;

        while(i < s.size()){
            while((c[s[i] - 'a']) > 0){
                z += s[i];
                c[s[i] - 'a'] -= 1;
            }
            i += 1;
            if(z.size())
                ans.push_back(z);
            z = "";
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.maxNumOfSubstrings("adefaddaccc");
    for(auto x:ans){
        cout<<x<<" ";
    }
}