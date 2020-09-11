#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }
}

void recursive_bubble_sort(int arr[], int size)
{
    // Base case
    if (size == 1)
        return;

    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);

    bubble_sort(arr, size - 1);
}

void selection_sort(int arr[], int size)
{
    int i = 0, j = 0;

    for (i = 0; i < size - 1; i++)
    {
        int pivot = arr[i];
        int index = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < pivot)
            {
                pivot = arr[j];
                index = j;
            }
        }

        if (pivot != arr[i])
            swap(arr[i], arr[index]);
    }
}

void insertion_sort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void recursive_insertion_sort(int arr[], int n)
{
    if (n <= 1)
        return;

    recursive_insertion_sort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void counting_sort(int arr[], int size)
{
    int count[size + 1] = {0};
    int output[size] = {0};

    for (int i = 0; i < size; i++)
        count[arr[i]]++;

    for (int i = 1; i <= size; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < size; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void display_sorted_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[10] = {10, 7, 1, 2, 3, 6, 8, 9, 4, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, arr_size);
    display_sorted_arr(arr, arr_size);
}