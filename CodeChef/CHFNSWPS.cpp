#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define int long long

void solve()
{
    int N;

    cin >> N;

    int A[N], B[N];

    unordered_map<int, int> setAB;
    multiset<int> setA, setB;

    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];

        setA.insert(A[i]);

        if (setAB.find(A[i]) == setAB.end())
            setAB[A[i]] = 1;
        else
        {
            setAB[A[i]] -= 1;
            if (setAB[A[i]] == 0)
                setAB.erase(A[i]);
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        cin >> B[i];

        setB.insert(B[i]);

        if (setAB.find(B[i]) == setAB.end())
            setAB[B[i]] = 1;
        else
        {
            setAB[B[i]] -= 1;
            if (setAB[B[i]] == 0)
                setAB.erase(B[i]);
        }
    }

    int cost = 0, tempA;

    vector<int> arrA, arrB;

    if (setAB.size())
        cout << "-1\n";
    else
    {
        multiset<int> resultA, resultB, resultAB;

        set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(resultA, resultA.end()));
        set_difference(setB.begin(), setB.end(), setA.begin(), setA.end(), inserter(resultB, resultB.end()));

        if (resultA.size())
        {
            auto itA = resultA.begin();
            auto itB = resultB.begin();
            int tempA, tempB;

            while (itA != resultA.end())
            {
                tempA = *itA;

                advance(itA, 1);

                if (tempA == *itA and itA != resultA.end())
                {
                    resultA.erase(resultA.find(*itA));
                    advance(itA, 1);
                }
            }

            while (itB != resultB.end())
            {
                tempB = *itB;

                advance(itB, 1);

                if (tempB == *itB and itB != resultB.end())
                {
                    resultB.erase(resultB.find(*itB));
                    advance(itB, 1);
                }
            }

            auto itAA = resultA.begin();
            auto itBB = resultB.rbegin();

            while (itAA != resultA.end())
            {
                cost += min(*itAA, *itBB);

                advance(itAA, 1);
                advance(itBB, 1);
            }

            cout << cost << "\n";
        }
        else
            cout << "0\n";
    }
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;

    while (t--)
        solve();
}