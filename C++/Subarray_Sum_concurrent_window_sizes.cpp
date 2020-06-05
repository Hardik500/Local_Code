#include <iostream>
#include <vector>

using namespace std;

int main(){
    int count = 0;

    cin>>count;

    while(count > 0){

        int LENGTH = 0, MAX_SUM = 0, first = 0;
        long long int SUM = 0;
        bool flag = false;

        cin>>LENGTH>>MAX_SUM;
    
        int ARRAY[LENGTH];

        for(int i = 0; i< LENGTH; i++){
            cin>> ARRAY[i];
        }

        for(int i = 0; i< LENGTH; i++){
            SUM += ARRAY[i];

            while(SUM > MAX_SUM){
                SUM -= ARRAY[first];
                first += 1;
            }

            if(SUM == MAX_SUM){
                cout<<first + 1<<" "<<i + 1<<"\n";
                flag = true;
            }

            if(flag){
                break;
            }
        }

        if(!flag){
            cout<<-1<<"\n";
        }

        count -= 1;
    }

    return 0;
}