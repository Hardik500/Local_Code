#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b)
{
    if (a == b)
        return false;

    vector<int> va, vb;
    string sa, sb;

    stringstream ssa(a), ssb(b);

    while (getline(ssa, sa, '.'))
        va.push_back(stoi(sa));

    while (getline(ssb, sb, '.'))
        vb.push_back(stoi(sb));

    int n = 0, m = 0;

    n = va.size();
    m = vb.size();

    int minimum = min(n, m);

    for (int i = 0; i < minimum; i++)
    {
        if (va[i] > vb[i])
            return true;
        if (va[i] < vb[i])
            return false;
    }

    if (n > m)
        return true;
    else
        return false;
}

void sorted_versions(string versions[], int size)
{

    sort(versions, versions + size, compare);

    for (int i = 0; i < size; i++)
        cout << versions[i] << "\n";
}

int main()
{
    string versions[] = {
        "1.3.0.9",
        "0.2.0",
        "3.1.2",
        "0.1.6",
        "5.0.0",
        "3.3.3.3",
        "3.3.3.3.3",
        "3.10",
        "0.2.0",
    };

    int size = sizeof(versions) / sizeof(versions[0]);

    //Given a string array versions sort it
    sorted_versions(versions, size);
}