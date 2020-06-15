#include <bits/stdc++.h>

using namespace std;

void permute(string x, int count = 1)
{   

    if (count == x.length())
    {   
        cout<<x<<" ";
        return;
    }

    for (int i = count; i < x.length(); i++)
    {
        swap(x[count], x[i]);
        permute(x, count+1);
        swap(x[i], x[count]);
    }
}

int main()
{
    string x = "ABCD";

    for (int i = 0; i < x.length(); i++)
    {
        swap(x[0], x[i]);
        permute(x);
        swap(x[0], x[i]);
    }
}