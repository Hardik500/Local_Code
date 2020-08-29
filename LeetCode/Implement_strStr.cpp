#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int sizeOfH = haystack.size();
        int sizeOfN = needle.size();

        if (sizeOfN == 0)
            return 0;

        int i = 0, j = 0, index = -1;

        while (i < sizeOfH && j < sizeOfN)
        {
            if(haystack.substr(i, sizeOfN) == needle)
                return i;            
            i++;
        }
        
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("mississippi", "issip") << "\n";
}