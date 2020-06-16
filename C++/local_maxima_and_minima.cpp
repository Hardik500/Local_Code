#include <bits/stdc++.h>

#define sizeOfA(x) sizeof(x) / sizeof(*x)

using namespace std;

int main()
{
    int arr[] = {1, 2, 3,-1, 4, 6, 5, 7};
    int maxima = INT_MIN, minima = INT_MAX;

    for (int i = 0; i < sizeOfA(arr); i++)
    {
        if ((arr[i - 1] < arr[i]) != (arr[i] < arr[i + 1]))
        {
            maxima = (maxima, arr[i]);
        }
    }

    for (int i = 0; i < sizeOfA(arr); i++)
    {
        if (arr[i - 1] > arr[i] and arr[i + 1] > arr[i])
        {
            minima = min(minima, arr[i]);
        }
    }

    cout << maxima << " " << minima;
}