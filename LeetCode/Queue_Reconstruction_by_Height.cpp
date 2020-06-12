#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> people = {{7, 0}, {4, 4}, {5, 2}, {7, 1}, {5, 0}, {6, 1}};
    vector<vector<int>> new_people = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

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
                if (new_people[j][0] == 0)
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

                if (new_people[j][0] == 0)
                {
                    emptyBlock += 1;
                }
                else
                {
                    filledBlock += 1;
                }
                //FIXME
                if ((emptyBlock + count) == people[i][1])
                {
                    if (new_people[emptyBlock + count][0] == 0)
                    {
                        new_people[emptyBlock + count] = people[i];
                        filled = false;
                    }
                    else{
                        while(j<people.size()){
                            if(new_people[j][0] == 0){
                                new_people[j] = people[i];
                                filled = false;
                                break;
                            }
                            j += 1;
                        }
                    }
                }
                j += 1;
            }
        }
    }

    for (auto x : new_people)
    {
        cout << x[0] << "\n";
    }
}