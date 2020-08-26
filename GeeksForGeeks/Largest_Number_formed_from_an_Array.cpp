#include <bits/stdc++.h>

using namespace std;

bool compare(int x, int y)
{
    string a = to_string(x);
    string b = to_string(y);

    return (a + b) > (b + a);
}

void form_largest_no(int arr[], int n)
{
    sort(arr, arr + n, compare);

    for (int i = 0; i < n; i++)
        cout << arr[i];

    cout << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        form_largest_no(arr, n);
    }
}