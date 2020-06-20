#include <bits/stdc++.h>

#define sizeOfArr(arr) sizeof(arr) / sizeof(*arr)

using namespace std;

int main()
{
    int arr[] = {2, 0, 2, 1, 1, 0};
    int countArr[] = {0, 0, 0};
    int sortedArr[sizeOfArr(arr)];

    for (int i = 0; i < sizeOfArr(arr); i++)
    {
        if (arr[i] == 0)
        {
            ++countArr[0];
        }
        if (arr[i] == 1)
        {
            ++countArr[1];
        }
        if (arr[i] == 2)
        {
            ++countArr[2];
        }
    }

    for (int i = 1; i < sizeOfArr(countArr); i++)
    {
        countArr[i] += countArr[i - 1];
    }

    for (int i = 0; i < sizeOfArr(arr); ++i)
    {
        if (arr[i] == 0)
        {
            sortedArr[countArr[0] - 1] = arr[i];
            --countArr[0];
        }
        if (arr[i] == 1)
        {
            sortedArr[countArr[1] - 1] = arr[i];
            --countArr[1];
        }
        if (arr[i] == 2)
        {
            sortedArr[countArr[2] - 1] = arr[i];
            --countArr[2];
        }
    }

    for(auto x: sortedArr){
        cout<<x<<"\n";
    }
}