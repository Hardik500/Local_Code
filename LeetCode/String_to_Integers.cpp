#include <bits/stdc++.h>

using namespace std;

int convert_to_int(string s)
{
    int size = s.size();

    int i = 0;
    int sign = 0;

    if(size == 0)
        return 0;

    while(i < size && s[i] == ' ')
        i++;

    while(i < size && (s[i] == '+' || s[i] == '-'))
        sign = (s[i++] == '-') ? -1 : 1;

    while(i < size && s[i] >= '0' && s[i] <= '9') {

    }
}

int main()
{
    string s;

    cin >> s;

    convert_to_int(s);
}