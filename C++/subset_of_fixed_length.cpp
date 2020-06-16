#include <bits/stdc++.h>

using namespace std;

unordered_set<string> st;

void subSets(string str, int n,int length = 0)
{
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<str[i]<<str[j]<<"\n";
        }
    }

    return;
}

int main()
{
    string str = "ABC";
    subSets(str, str.length(), 2);
}