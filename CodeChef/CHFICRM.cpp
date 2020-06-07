#include <bits/stdc++.h>

using namespace std;

void first(){
    int N = 0;
    cin>>N;
    bool unable = false;
    int P[N], sum = 0;
    unordered_map<int, int> d;
    
    for(int i = 0; i< N; i++){
        cin>>P[i];
        if(P[i] == 5){
            if (d.count(5) > 0) {
                d[5] += 1;
            } else {
                d.insert(pair<int,int>(5, 1));
            }
        }
        else if(P[i] == 10){
            if (d.count(5) > 0 and d[5] >= 1) {
                d[5] -=1;
                if(d.count(10) > 0){
                    d[10] += 1;
                }
                else{
                    d.insert(pair<int,int>(10, 1));
                }
            }
            else{
                unable = true;
                cout<<"NO";
                break;
            }
        }
        else{
            if(d.count(10) > 0 and d[10] >= 1){
                d[10] -= 1;
                if(d.count(15) > 0){
                    d[15] += 1;
                }
                else{
                    d.insert(pair<int,int>(15, 1));
                }
            }
            else if(d.count(5) > 0 and d[5] >= 2){
                d[5] -= 2;
                if(d.count(15) > 0){
                    d[15] += 1;
                }
                else{
                    d.insert(pair<int,int>(15, 1));
                }
            }
            else{
                unable = true;
                cout<<"NO";
                break;
            }
        }
    }
    
    if(not unable){
        cout<<"YES";
    }
    cout<<"\n";

}

int main(){
    int count = 0;
    cin>>count;
    while(count >= 0){
        first();
        count -= 1;
    }
}