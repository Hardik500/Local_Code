#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> people = {{8,2},{4,2},{4,5},{2,0},{7,2},{1,4},{9,1},{3,1},{9,0},{1,0}};
    vector<vector<int>> new_people = {};

    for(auto x: people){
        new_people.push_back({-1,-1});
    }

    auto comp = [](vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        else
        {
            return (a[0] < b[0]);
        }
    };

    sort(people.begin(), people.end(), comp);

    bool filled = false;
    int j = 0;

    for (int i = 0; i < people.size(); i++)
    {
        filled = true;
        j = 0;

        if (people[i][1] == 0)
        {
            while (filled)
            {
                if (new_people[j][0] == -1)
                {
                    new_people[j] = people[i];
                    filled = false;
                }
                else
                {
                    j += 1;
                }
            }
        }
        else
        {
            int count = 0, j = 0, emptyBlock = 0, filledBlock = 0;

            while (filled)
            {
                if (new_people[j][0] >= people[i][0] and (new_people[j][0] == people[i][0] ? new_people[j][1] != people[i][1] : true))
                {
                    count += 1;
                    filledBlock -= 1;
                }

                if (new_people[j][0] == -1)
                {
                    emptyBlock += 1;
                }
                else
                {
                    filledBlock += 1;
                }
                if ((emptyBlock + count) == people[i][1])
                {
                    if (filledBlock > 0)
                    {
                        if (new_people[emptyBlock + count + filledBlock][0] == -1)
                        {
                            new_people[emptyBlock + count + filledBlock] = people[i];
                            filled = false;
                        }
                        else
                        {
                            j = filledBlock + emptyBlock + count;
                            while (j < people.size())
                            {
                                if (new_people[j][0] == -1)
                                {
                                    new_people[j] = people[i];
                                    filled = false;
                                    break;
                                }
                                j += 1;
                            }
                        }
                    }
                    else
                    {
                        if (new_people[emptyBlock + count][0] == -1)
                        {
                            new_people[emptyBlock + count] = people[i];
                            filled = false;
                        }
                        else
                        {
                            j = emptyBlock + count;
                            while (j < people.size())
                            {
                                if (new_people[j][0] == -1)
                                {
                                    new_people[j] = people[i];
                                    filled = false;
                                    break;
                                }
                                j += 1;
                            }
                        }
                    }
                }
                j += 1;
            }
        }
    }

    cout << "[";

    for (int i = 0;i<new_people.size();i++)
    {
        if (i == new_people.size() - 1)
        {
            cout << "[" << new_people[i][0] << "," << new_people[i][1] << "]";
        }
        else
        {
            cout << "[" << new_people[i][0] << "," << new_people[i][1] << "],";
        }
    }

    cout << "]\n";
}

//OR (best soln)

/*

bool pro(const pair<int,int> & x, const pair<int,int> & y)
{
    if(x.first!=y.first)
    {
        return x.first<y.first;
    }
    else
    {
        return x.second>y.second;
    }
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
     
        vector<pair<int,int>> a;
        int n=p.size();
        vector<vector<int>> ans(n);

        if(n==0)
        {
            return ans;
        }
        int i,x,y;
        
        for(i=0;i<n;i++)
        {
            x=p[i][0];
            y=p[i][1];
            a.push_back({x,y});
        }
        
        sort(a.begin(),a.end(),pro);
        
        int an[n],j;
        
        
        for(i=0;i<n;i++)
        {
            an[i]=-1;
        }
        int count=0;
        for(i=0;i<n;i++)
        {
            cout<<a[i].first<<" "<<a[i].second<<"     "; 
            x=a[i].second;
            count=0;
            for(j=0;j<n;j++)
            {
                if(an[j]==-1)
                {
                    count++;
                }
                if(count>x)
                {
                    an[j]=i;
                    ans[j].push_back(a[i].first);
                    ans[j].push_back(a[i].second);
                    break;
                }
            }
        }
        
        
       return ans;
        
    }
};

*/
