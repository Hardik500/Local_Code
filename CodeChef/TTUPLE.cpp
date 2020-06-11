#include <bits/stdc++.h>

using namespace std;

int smallest(int x, int y, int z)
{
    int minimum = 0;
    if (x != 0)
    {
        if (y != 0)
        {
            if (z != 0)
            {
                if (z <= x and z <= y)
                {
                    return z;
                }
            }
            else
            {
                if (x <= y)
                {
                    return x;
                }
                else
                {
                    return y;
                }
            }

            if (y <= x and y <= z)
            {
                return y;
            }
        }
        else
        {
            if (x <= z)
            {
                return x;
            }
            else
            {
                return z;
            }
        }
        if (x <= y and x <= z)
        {
            return x;
        }
    }
    else
    {
        if (y <= z)
        {
            return y;
        }
        else
        {
            return z;
        }
    }
    return 0;
}

void first()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;

    int doA = x - a, doB = y - b, doC = z - c;
    int moA = x / a, moB = y / b, moC = z / c;
    int countS = 4, countM = 4, count = 0;
    bool found = false;

    int smallestOfNos = smallest(doA, doB, doC);

    if (moA == moB and moB == moC and moA == moC and a * moA == x and b * moB == y and c * moC == z)
    {
        countM = 1;
        found = true;
    }
    else
    {
        if (moA == moB)
        {
            if (a * moA == x and b * moB == y)
            {
                if (c == z)
                {
                    countM = 1;
                    found = true;
                }
                else
                {
                    countM = 2;
                    found = true;
                }
            }
        }
        else if (moA == moC)
        {
            if (a * moA == x and c * moC == z)
            {
                if (c == z)
                {
                    countM = 1;
                    found = true;
                }
                else
                {
                    countM = 2;
                    found = true;
                }
            }
        }
        else if (moB == moC)
        {
            if (b * moB == y and c * moC == z)
            {
                if (a == x)
                {
                    countM = 1;
                    found = true;
                }
                else
                {
                    countM = 2;
                    found = true;
                }
            }
        }
    }

    if (doA == doB and doB == doC and doA == doC)
    {
        countS = 1;
        found = true;
    }
    else
    {
        if (a < x)
        {
            a += smallestOfNos;
        }
        if (b < y)
        {
            b += smallestOfNos;
        }
        if (c < z)
        {
            c += smallestOfNos;
        }

        if (a == x and b == y and c == z)
        {
            countS = 1;
            found = true;
        }
        else if (a == x and b == y)
        {
            countS = 2;
            found = true;
        }
        else if (a == x and c == z)
        {
            countS = 2;
            found = true;
        }
        else if (b == y and c == z)
        {
            countS = 2;
            found = true;
        }
    }

    if (countS < countM)
    {
        count = countS;
    }
    else
    {
        count = countM;
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