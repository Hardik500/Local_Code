// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class _stack
{
    stack<int> s;
    int minEle;

public:
    int getMin();
    int pop();
    void push(int);
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        _stack *a = new _stack();
        while (q--)
        {

            int qt;
            cin >> qt;

            if (qt == 1)
            {
                //push
                int att;
                cin >> att;
                a->push(att);
            }
            else if (qt == 2)
            {
                //pop
                cout << a->pop() << " ";
            }
            else if (qt == 3)
            {
                //getMin
                cout << a->getMin() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :q.
    int getMin();
    int pop();
    void push(int);
};
*/

//Note: Even custom input is right but not the right solution on submission
// int minimum = INT_MAX;

// /*returns min element from stack*/
// int _stack ::getMin()
// {
//     return minimum == INT_MAX ? -1 : minimum;
// }

// /*returns poped element from stack*/
// int _stack ::pop()
// {
//     int temp = s.size() ? s.top() : -1;

//     if (s.size())
//         s.pop();

//     if (temp == minimum || s.size() == 0)
//         minimum = s.size() ? s.top() : INT_MAX;

//     return temp;
// }

// /*push element x into the stack*/
// void _stack::push(int x)
// {
//     s.push(x);
//     minimum = min(minimum, x);
// }

//Geeks Solution
int _stack ::getMin()
{
    if (s.empty())
        return -1;
    else
        return minEle;
}
int _stack ::pop()
{
    if (s.empty())
    {
        return -1;
    }
    int t = s.top();
    s.pop();
    if (t < minEle)
    {
        int k = minEle;
        minEle = 2 * minEle - t;
        return k;
    }
    else
        return t;
}
void _stack::push(int x)
{
    if (s.empty())
    {
        minEle = x;
        s.push(x);
        return;
    }
    if (x < minEle)
    {
        s.push(2 * x - minEle);
        minEle = x;
    }
    else
        s.push(x);
}