#include <bits/stdc++.h>

using namespace std;

void first()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;

    int doA = x - a, doB = y - b, doC = z - c;
    int moA, moB, moC;

    if (a != 0)
    {
        moA = x / a;
    }
    else
    {
        moA = 0;
    }

    if (b != 0)
    {
        moB = y / b;
    }
    else
    {
        moB = 0;
    }

    if (c != 0)
    {
        moC = z / c;
    }
    else
    {
        moC = 0;
    }

    int count = 0;

    if ((doA == doB and doB == doC and doA == doC) or (moA * a == x and moB * b == y and moC * c == z))
    {
        count = 1;
    }
    else if ((doA == 0 and doB == doC) or (doB == 0 and doA == doC) or (doC == 0 and doA == doC))
    {
        count = 1;
    }
    else if (doA == doB)
    {
        count = 2;
    }
    else if (doA == doC)
    {
        count = 2;
    }
    else if (doC == doB)
    {
        count = 2;
    }
    else if (doA == 0 or doB == 0 or doC == 0)
    {
        count = 2;
    }
    else if (moA * a == x and moB * b == y)
    {
        count = 2;
    }
    else if (moC * c == z and moB * b == y)
    {
        count = 2;
    }
    else if (moA * a == x and moC * c == z)
    {
        count = 2;
    }
    else
    {
        count = 3;
    }

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