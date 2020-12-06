#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> mergedIntervals;

        if (intervals.size() == 0)
            return mergedIntervals;

        sort(intervals.begin(), intervals.end());
        vector<int> tmp = intervals[0];

        for(auto it:intervals){
            if(tmp[1] >= it[0])
                tmp[1] = max(tmp[1], it[1]);
            else{
                mergedIntervals.push_back(tmp);
                tmp = it;
            }
        }

        mergedIntervals.push_back(tmp);
        return mergedIntervals;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    for (auto x : s.merge(intervals))
    {
        for (auto y : x)
            cout << y << " ";
        cout << "\n";
    }
}