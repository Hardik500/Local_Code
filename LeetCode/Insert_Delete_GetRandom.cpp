#include <bits/stdc++.h>

using namespace std;

class RandomizedSet
{
    unordered_map<int, int> s;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (s.find(val) == s.end())
        {
            s[val] = val;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (s.find(val) != s.end())
        {
            s.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        auto it = s.begin();
        advance(it, rand() % s.size());
        int random_key = it->first;
        return random_key;
    }
};

int main()
{

    RandomizedSet *obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->insert(2);
    bool param_3 = obj->insert(3);
    bool param_4 = obj->insert(4);

    // bool param_5 = obj->remove(3);
    int param_6 = obj->getRandom();
    cout<<param_6<<"\n";
}