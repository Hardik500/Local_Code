#include <bits/stdc++.h>

using namespace std;

void first()
{
    int a, b, c, x, y, z, count = 0;
    cin >> a >> b >> c;
    cin >> x >> y >> z;

    if (count > 3)
    {
        cout << 3 << "\n";
    }
    else
    {
        cout << count << "\n";
    }
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