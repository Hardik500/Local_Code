#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "aaaaaa", t = "bbaaaa";
    bool notfound = false;
    int lastIndex = -1;
    int currentIndex = -1;

    for (int i = 0; i < s.length(); i++)
    {
        currentIndex = t.find(s[i], lastIndex + 1);
        if (currentIndex < t.length())
        {
            lastIndex = currentIndex;
            notfound = false;
        }
        else
        {
            notfound = true;
            break;
        }
    }

    if (notfound)
    {
        cout << "false"
             << "\n";
    }
    else
    {
        cout << "true"
             << "\n";
    }
}