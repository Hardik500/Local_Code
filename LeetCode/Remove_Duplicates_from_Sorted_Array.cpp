#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int s = 0, e = 1, len = 1;
        
        while(e < nums.size()) {
            if(nums[e] != nums[s]){
                nums[s + 1] = nums[e];
                s++;
                len++;
            }
            e++;
        }
        
        return len;
    }
};

int main(){
    Solution s;

    vector<int> x = {1,1,2};

    s.removeDuplicates(x);
}