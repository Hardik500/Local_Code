#include <bits/stdc++.h>

using namespace std;

void first(){
    string str;
    int i=0, count=0;
    getline(cin, str);
    while(i<str.size() - 1){
        if(str[i] == 'x' && str[i+1] == 'y'){
            count += 1;
            i+=1;
        }
        else if(str[i] == 'y' && str[i+1] == 'x'){
            count += 1;
            i+=1;
        }
        
        i += 1;
    }
    cout<<count<<"\n";
}

int main(){
    int count = 0;
    cin>>count;
    cin.ignore(256, '\n');
    while(count > 0){
        first();
        count -= 1;
    }
}