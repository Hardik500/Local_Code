// C++ program to print all permutations with 
// duplicates allowed using rotate() in STL 
#include <bits/stdc++.h> 
using namespace std; 

void sortedStack(stack <int> s, int item){
	cout<<item<<"\n";
}

void sort(stack <int> s){
	if(!s.empty())
	{
		int temp = s.pop();
		sort(s);
		sortedStack(s, temp);
	}
}

void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
}

// Driver code 
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack <int> s;
	s.push(5);
	s.push(15);
	s.push(50);
	s.push(-15);
	cout<<"Stack\n";
	showstack(s);
	cout<<"Sorted stack\n";
	sort(s);
	showstack(s);
	return 0;
} 
