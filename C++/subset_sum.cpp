#include <bits/stdc++.h>

using namespace std;

static int total_nodes;

vector<vector<int>> finalAns;

int subset_sum(vector<int> weights, int size, int maximum, int current_weight = 0, int previous_weight = 0, int index = 0, vector<int> nodes = {})
{
    if (current_weight == maximum)
    {
        finalAns.push_back(nodes);
        return 1;
    }
    else if (current_weight > maximum)
    {
        return 0;
    }
    else
    {
        for (int i = index; i < size; i++)
        {
            current_weight += weights[i];
            nodes.push_back(weights[i]);

            subset_sum(weights, size, maximum, current_weight, weights[i], i + 1, nodes);

            current_weight -= weights[i];
            nodes.pop_back();
        }
    }

    return 0;
}

void generateSubsets(vector<int> weights, int size, int maximum)
{
    subset_sum(weights, size, maximum, 0);

    for (auto x : finalAns)
    {
        for (auto p : x)
        {
            cout << p << " ";
        }

        cout << "\n";
    }
}

int main()
{
    vector<int> weights = {10, 5, 18, 12, 7, 20, 15};
    int size = weights.size();

    generateSubsets(weights, size, 35);
}