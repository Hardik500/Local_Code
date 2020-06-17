#include <bits/stdc++.h>

using namespace std;

void first()
{
    int length = 0, countEven = 0, countOdd = 0, wrongEven = 0, wrongOdd = 0;

    cin >> length;

    int arr[length];

    bool notFound = false;

    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2)
            countOdd += 1;
        else
            countEven += 1;
    }

    if (length % 2 == 0)
    {
        if (countEven != countOdd)
        {
            cout << -1 << "\n";
            notFound = true;
        }
    }
    else
    {
        if ((countEven - 1) == countOdd)
        {
        }
        else if (countEven == (countOdd - 1))
        {
        }
        else
        {
            cout << -1 << "\n";
            notFound = true;
        }
    }

    if (not notFound)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] % 2 and i % 2 == 0)
                wrongOdd += 1;
            else if (arr[i] % 2 == 0 and i % 2)
                wrongEven += 1;
        }

        if(wrongEven == wrongOdd){
            cout<<(wrongOdd + wrongEven)/2<<"\n";
        }
        else{
            if(wrongOdd > 0 and wrongEven == 0){
                cout<<-1<<"\n";
            }
            else if(wrongEven > 0 and wrongOdd == 0){
                cout<<-1<<"\n";
            }
            else if(wrongOdd == 0 and wrongEven == 0){
                cout<<0<<"\n";
            }
            else{
                cout<<-1<<"\n";
            }
        }
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