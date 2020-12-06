// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Space Complexity O(1)
    // void findTwoElement(int *arr, int n) {

    //     int tortoise = arr[0] - 1;
    //     int hare = arr[0] - 1;

    //     do
    //     {
    //         tortoise = arr[tortoise] - 1;
    //         hare = arr[hare] - 1;
    //     } while (tortoise != hare);

    //     tortoise = arr[0] - 1;

    //     while(tortoise != hare){
    //         tortoise = arr[tortoise] - 1;
    //         hare = arr[hare] - 1;
    //     }

    //     int gotSum = 0;
    //     int actualSum = 0;

    //     hare += 1;

    //     for(int i = 0; i < n; i++){
    //         gotSum += arr[i];
    //     }

    //     gotSum -= hare;

    //     actualSum = (int)((n) * (n + 1))/2;

    //     int missingNumber;

    //     if(gotSum > actualSum){
    //         missingNumber = gotSum - actualSum;
    //     }
    //     else{
    //         missingNumber = actualSum - gotSum;
    //     }

    //     cout<<"ACTUAL SUM: "<<actualSum<<"\nGOT SUM: "<<gotSum<<"\nMISSING NUMBER: "<<missingNumber<<"\nDUPLICATE NUMBER: "<<hare<<"\n";

    // }

    void findTwoElement(int *arr, int n)
    {
        int ump[n + 1] = {0};

        for (int i = 1; i <= n; i++){
            ump[arr[i - 1]] += 1;
        }

        int missingNumber = 0;
        int duplicateNumber = 0;

        for (int i = 1; i <= n; i++)
        {
            if (ump[i] == 0)
                missingNumber = i;
            if (ump[i] > 1)
                duplicateNumber = i;
        }

        cout << missingNumber << " " << duplicateNumber << "\n";
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        ob.findTwoElement(a, n);
    }
}