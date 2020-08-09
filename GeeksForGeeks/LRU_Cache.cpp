// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// design the class:

//Note: Some complications (Basically when you access the item it needs to be pushed front too)
// class LRUCache
// {
// private:
//     int size;
//     int capacity = 0;
//     vector<pair<int, int>> v;
//     unordered_map<int, int> m;

// public:
//     LRUCache(int cap)
//     {
//         // constructor for cache
//         size = cap;
//     }

//     int get(int key)
//     {
//         // this function should return value corresponding to key
//         if(m.find(key) != m.end()){
//             if(m[key] >= 0){
//                 return v[m[key]].second;
//             }
//             return -1;
//         }
//         return -1;
//     }

//     void set(int key, int value)
//     {
//         // storing key, value pair
//         bool found = false;
//         for(auto iter = v.begin(); iter != v.end(); ++iter)
//         {
//             if (iter->first == key)
//             {
//                 found = true;
//                 v.erase(iter);
//                 v.push_back(make_pair(key, value));

//                 for(auto &x:m){
//                     if(x.second >= v.size() - 1)
//                         x.second -= 1;
//                 }

//                 m[key] = v.size() - 1;
//                 break;
//             }
//         }

//         if (!found)
//         {
//             v.push_back(make_pair(key, value));
//             m[key] = v.size() - 1;
//             capacity += 1;

//             if (capacity > size){
//                 int key = v.begin()->first;

//                 for(auto &x:m){
//                     if(x.second >= 0){
//                         x.second -= 1;
//                     }
//                 }

//                 m[key] = -1;
//                 v.erase(v.begin());
//             }
//         }
//     }
// };

//Right Answer

class LRUCache
{
private:
    int maxSize;
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> ma;

public:
    LRUCache(int cap)
    {
        // constructor for cache
        maxSize = cap;
        dq.clear();
        ma.clear();
    }

    int get(int key)
    {
        if (ma.find(key) == ma.end())
        {
            return -1;
        }
        auto it = ma.find(key);
        int d = (*(it->second)).second;
        dq.erase(it->second);
        dq.push_front({key, d});
        ma[key] = dq.begin();
        return d;
    }

    void set(int key, int value)
    {
        if (ma.find(key) == ma.end()) //Key not found
        {
            if (dq.size() == maxSize) // Capacity at max
            {
                int Lx = dq.back().first;
                int Ly = dq.back().second;
                dq.pop_back();
                dq.push_front({key, value});
                ma.erase(Lx);
                ma[key] = dq.begin();
            }
            else
            {
                dq.push_front({key, value});

                ma[key] = dq.begin();
            }
        }
        else
        {
            auto it = ma.find(key);
            dq.erase(it->second);
            dq.push_front({key, value});

            ma[key] = dq.begin();
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;

        while (queries)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }

            queries -= 1;
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends