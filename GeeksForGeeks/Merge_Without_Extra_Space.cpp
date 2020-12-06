#include <bits/stdc++.h>

using namespace std;

// TIME COMPLEXITY (n*m)

// void insertionSort(vector<int> &arr, int n)
// {
//     int i, key, j;
//     for (i = 1; i < n; i++)
//     {
//         key = arr[i];
//         j = i - 1;

//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }

//         arr[j + 1] = key;
//     }
// }

// void merge(vector<int> &arr1, vector<int> &arr2, int n, int m)
// {
//     int i = 0;
//     int j = 0;

//     while (i < n)
//     {
//         if (i < n && arr1[i] > arr2[j])
//             swap(arr1[i], arr2[j]);

//         i++;
//         insertionSort(arr2, m);
//     }
// }

// GAP METHOD O(NlogN)
// FIXME: Some inconsistencies are there but yeah the approach is right
// bool compare(int ele1, int ele2)
// {
//     if (ele1 > ele2)
//         return true;
//     return false;
// }

// void merge(vector<int> &arr1, vector<int> &arr2, int n, int m)
// {
//     int gap = (n + m + 1) / 2;

//     int i = 0, j = 0;

//     int counter = n + m - 1;

//     do
//     {
//         i = 0;
//         j = i + gap;

//         while (j < (m + n))
//         {
//             if (i > n)
//                 compare(arr2[i], arr2[j]) ? swap(arr2[i], arr2[j]) : swap(arr2[i], arr2[i]);
//             else if (j < n)
//                 compare(arr1[i], arr1[j]) ? swap(arr1[i], arr1[j]) : swap(arr1[i], arr1[i]);
//             else
//                 compare(arr1[i], arr2[(j + 1)/counter]) ? swap(arr1[i], arr2[(j + 1)/counter]) : swap(arr1[i], arr1[i]);

//             i++;
//             j++;
//         }

//         if (gap == 1)
//             gap = 0;

//         gap = (gap + 1) / 2;
//         counter++;
//     } while (gap != 0);
// }

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
 
void merge(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
 
        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
 
        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}

int main()
{
    vector<int> arr1 = {10, 27, 38, 43, 82};
    vector<int> arr2 = {3, 9};

    merge(arr1, arr2, arr1.size(), arr2.size());

    for (auto x : arr1)
        cout << x << " ";

    cout << "\n";

    for (auto x : arr2)
        cout << x << " ";
}