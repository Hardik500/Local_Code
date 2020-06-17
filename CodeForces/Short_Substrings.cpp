#include <bits/stdc++.h>

using namespace std;

void first()
{
    string x, y = "";
    char z;
    cin >> x;

    if (x.length() == 2)
    {
        cout << x << "\n";
    }
    else
    {
        int i = 1;

        y+= x[0];

        while (i < x.length())
        {
            y += x[i];
            z = x[i];
            i += 2;
        }
    }

    cout << y << "\n";
}

int main()
{
    int count = 0;
    cin >> count;

    while (count--)
    {
        first();
    }
}