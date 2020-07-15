#include <bits/stdc++.h>

using namespace std;


//Lexcographic Order

//Naive Method
void generate_suffixes(string s, int size)
{
    vector<string> suffixes;
    vector<int> suffixArray;

    int i = size - 1;

    suffixes.push_back("$" + s);

    for (int len = 0; len < size; len++)
    {
        suffixes.push_back(s.substr(len, i + 1) + "$" + s.substr(0, len));
        i += 1;
    }

    sort(suffixes.begin(), suffixes.end());

    for (auto x : suffixes)
        suffixArray.push_back(size - x.find("$"));
    
    for (auto x : suffixArray)
        cout<<x<<" ";

}

int main()
{
    string s;
    int sizeOfString;
    cin>>s;
    sizeOfString = s.size();
    generate_suffixes(s, sizeOfString);
}