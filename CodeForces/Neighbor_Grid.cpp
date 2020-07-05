#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int h, w;
        bool flag = true;
        cin >> h >> w;
        int arr[h][w];
        int input_arr[h][w];
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if ((i == 0 and j == 0) || (i == 0 and j == w - 1) || (j == 0 and i == h - 1) || (i == h - 1 and j == w - 1))
                {
                    arr[i][j] = 2;
                }
                else if (i == 0 || j == 0 || i == h - 1 || j == w - 1)
                {
                    arr[i][j] = 3;
                }
                else
                {
                    arr[i][j] = 4;
                }
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> input_arr[i][j];
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (input_arr[i][j] > arr[i][j])
                {
                    flag = false;
                    cout << "NO\n";
                    break;
                }
            }

            if (not flag)
            {
                break;
            }
        }

        if (flag)
        {
            cout<<"YES\n";
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    cout<<arr[i][j]<<" ";
                }

                cout<<"\n";
            }
        }
    }
    return 0;
}