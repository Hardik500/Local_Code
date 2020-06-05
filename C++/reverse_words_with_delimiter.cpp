#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int count = 0;
    
    cin>>count;
    
	for(int i=0;i<=count;i++){
        string arr;

        getline(cin, arr); 

	    vector<int> index;
        vector<char> newStr;
        
        if(arr.size() != 0){
            for(int i=arr.size() - 1;i>=0;i--){
                if(arr[i] == '.'){
                    index.push_back(i);
                }
            }
        
            index.push_back(-1);
        
            int prevIndex = arr.size();
        
            for(int i=0;i<index.size();i++){
                int len = index[i] + 1;
        
                while(len < prevIndex){
                    newStr.push_back(arr[len]);
                    len += 1;
                }
        
                if(index[i] != -1){
                    newStr.push_back('.');
                }
        
                prevIndex = index[i];
            }
        
            for(int i=0;i<newStr.size();i++){
                cout<<newStr[i];
            }

            cout<<"\n";
        }
	}
	return 0;
}