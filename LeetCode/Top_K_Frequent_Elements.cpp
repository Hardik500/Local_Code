#include <bits/stdc++.h>

using namespace std;

bool comp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> score;

        for (auto num : nums)
            score[num]++;

        vector<pair<int, int>> elems(score.begin(), score.end());

        sort(elems.begin(), elems.end(), comp);

        vector<int> listOfTop;

        int i = 0;

        while(k--)
        {
            listOfTop.push_back(elems[i].first);
            i++;
        }

        return listOfTop;
    }
};

int main()
{
    Solution s;

    int k = 2;
    vector<int> nums = {4, 4, 4, 5, 5, 5, 2, 2, 3};

    s.topKFrequent(nums, k);
}