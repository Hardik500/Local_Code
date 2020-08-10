#include <bits/stdc++.h>

using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump[], int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        cout << tour(p, n) << endl;
    }
}
// } Driver Code Ends

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/

//Brute Force ( O(n^2) )

int tour(petrolPump p[], int n)
{
    int count = n, i = 0;

    int petrol = 0;

    while (i < n)
    {
        petrolPump start = p[i];

        petrol = start.petrol - start.distance;

        int j = i + 1;

        while (count)
        {
            if (j == n)
                j = 0;

            petrolPump next = p[j];

            if (petrol<0)
                break;

            petrol += next.petrol - next.distance;

            j += 1;
            count -= 1;
        }

        if (!count)
            return i;

        i += 1;
        count = n;
    }

    count = 0;

    return -1;
}