#include <bits/stdc++.h>

using namespace std;

int convert_to_int(string s)
{
    int size = s.size();

    int i = 0;
    int sign = 1;
    int result = 0;

    if (size == 0)
        return 0;

    while (i < size && s[i] == ' ')
        i++;

    while (i < size && (s[i] == '+' || s[i] == '-'))
        sign = (s[i++] == '-') ? -1 : 1;

    while (i < size && s[i] >= '0' && s[i] <= '9')
    {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
            return (sign == 1) ? INT_MAX : INT_MIN;
        result = result * 10 + (s[i++] - '0');
    }

    return result * sign;
}

int main()
{
    string s;

    cin >> s;

    int x = convert_to_int(s);

    cout << x;
}