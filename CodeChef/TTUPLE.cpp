#include <bits/stdc++.h>

using namespace std;

void first()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;

    int doA = x - a, doB = y - b, doC = z - c;
    int moA, moB, moC;

    int ddAB = b - a;
    int ddBC = c - b;
    int ddxy = y - x;
    int ddyz = z - y;
    bool doabxy = false, dobcyz = false;

    if (ddxy != 0 and ddAB % ddxy == 0)
    {
        doabxy = true;
    }
    if (ddyz != 0 and ddBC % ddyz == 0)
    {
        dobcyz = true;
    }

    bool found = false;

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

    if ((doA == doB and doB == doC and doA == doC) or ((moA == moB and moB == moC and moC == moA) and (moA * a == x and moB * b == y and moC * c == z)))
    {
        count = 1;
    }
    else if ((doA == 0 and doB == doC) or (doB == 0 and doA == doC) or (doC == 0 and doA == doC))
    {
        count = 1;
    }
    else if((doA == 0 and doB == 0) or (doC == 0 and doB == 0) or (doA == 0 and doC == 0)){
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
    else if ((moA == moB) and (moA * a == x and moB * b == y))
    {
        count = 2;
    }
    else if ((moB == moC) and (moC * c == z and moB * b == y))
    {
        count = 2;
    }
    else if ((moA == moC) and (moA * a == x and moC * c == z))
    {
        count = 2;
    }
    else if (doabxy and dobcyz)
    {
        count = 2;
    }
    else if (moA == moB)
    {
        a *= moA;
        b *= moB;

        if (b != y and a == x)
        {
            doB = y - b;
            doC = z - c;

            if (doB == doC)
            {
                count = 2;
            }
        }
        else if (b == y and a != x)
        {
            doA = x - a;
            doC = z - c;

            if (doA == doC)
            {
                count = 2;
            }
        }
        else if (b == y and a == x)
        {
            if (c == z)
            {
                count = 1;
            }
            else
            {
                count = 2;
            }
        }
        else
        {
            doB = y - b;
            doC = z - c;
            doA = x - a;

            if (doA == 0)
            {
                if (doB == doC)
                {
                    count = 2;
                }
                else
                {
                    count = 3;
                }
            }
            else if (doB == 0)
            {
                if (doA == doC)
                {
                    count = 2;
                }
                else
                {
                    count = 3;
                }
            }
            else if (doC == 0)
            {
                if (doA == doB)
                {
                    count = 2;
                }
                else
                {
                    count = 3;
                }
            }
            else if (doB == doA == doC)
            {
                count = 2;
            }
            else
            {
                count = 3;
            }
        }
    }
    else if (moB == moC)
    {

        c *= moC;
        b *= moB;

        if (b != y and c == z)
        {
            doB = y - b;
            doA = x - a;

            if (doB == doA)
            {
                count = 2;
            }
        }
        else if (b == y and c != z)
        {
            doA = x - a;
            doC = z - c;

            if (doA == doC)
            {
                count = 2;
            }
        }
        else if (b == y and c == z)
        {
            if (a == x)
            {
                count = 1;
            }
            else
            {
                count = 2;
            }
        }
        else
        {
            doB = y - b;
            doC = z - c;
            doA = x - a;

            if (doA == 0)
            {
                if (doB == doC)
                {
                    count = 2;
                }
                else
                {
                    count = 3;
                }
            }
            else if (doB == 0)
            {
                if (doA == doC)
                {
                    count = 2;
                }
                else
                {
                    count = 3;
                }
            }
            else if (doC == 0)
            {
                if (doA == doB)
                {
                    count = 2;
                }
                else
                {
                    count = 3;
                }
            }
            else if (doB == doA == doC)
            {
                count = 2;
            }
            else
            {
                count = 3;
            }
        }
    }
    else if (moC == moA)
    {
        c *= moC;
        a *= moA;

        if (a != x and c == z)
        {
            doA = x - a;
            doB = y - b;

            if (doB == doA)
            {
                count = 2;
            }
        }
        else if (a == x and c != z)
        {
            doB = y - b;
            doC = z - c;

            if (doB == doC)
            {
                count = 2;
            }
        }
        else if (a == x and c == z)
        {
            if (b == y)
            {
                count = 1;
            }
            else
            {
                count = 2;
            }
        }
        else
        {
            doB = y - b;
            doC = z - c;
            doA = x - a;

            if (doA == 0)
            {
                if (doB == doC)
                {
                    count = 2;
                }
                else
                {
                    count = 3;
                }
            }
            else if (doB == 0)
            {
                if (doA == doC)
                {
                    count = 2;
                }
                else
                {
                    count = 3;
                }
            }
            else if (doC == 0)
            {
                if (doA == doB)
                {
                    count = 2;
                }
                else
                {
                    count = 3;
                }
            }
            else if (doB == doA == doC)
            {
                count = 2;
            }
            else
            {
                count = 3;
            }
        }
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