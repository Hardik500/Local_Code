#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 

#define sizeOfA(n) sizeof(n) / sizeof(*n)
#define sizeOfV(n) n.size()

using namespace std;

int isPair(vector<int> arr, int length, int X){
    int first = 0;
    int second = length - 1;
    int total = 0;

    while(first < second){
        if(arr[first] + arr[second] == X){
            total += 1;
            first += 1;
        }
        else if(arr[first] + arr[second] > X){
            second -= 1;
        }
        else{
            first += 1;
        }
    }

    return total;
}


int main()
{
    int count = 0;
    
    cin>>count;
    
    for(int i=0;i<count;i++){
        int total = 0, length = 0, input;
        
        cin>>length;

        vector<int> vec(length);
        
        for(int j=0;j<length;++j){
            cin>>vec[j];
        }

        sort(vec.begin(), vec.end());

        for(auto j: vec){
            total += isPair(vec, length,j);
        }

        if(total == 0){
            cout<<-1<<"\n";
        }
        else{
            cout<<total<<"\n";
        }
    }

    return 0;
}