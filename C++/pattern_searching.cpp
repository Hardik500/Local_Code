#include <bits/stdc++.h>

using namespace std;

//O(m*(n-m+1)) - Worst Case
//O(n) - Best Case
void naive_soln(string pat, string txt)
{
    int i = 0, counter = 0, j = 0, k = 0;

    while (i <= txt.size() - pat.size())
    {
        j = i;

        while (txt[i] == pat[k] && i < txt.size() && counter < pat.size())
        {
            i += 1;
            counter += 1;
            k += 1;
        }

        if (counter == pat.size())
            cout << j << " " << i - 1 << "\n";

        counter = 0;
        i = j + 1;
        k = 0;
    }
}

//The time complexity of KMP algorithm is O(n + m) (or O(n)) in the worst case.
void knuth_moris_pratt_soln(string pat, string txt)
{
    int sizeOfPattern = pat.size();
    int sizeOfString = txt.size();

    int lps[sizeOfPattern];

    for (int i = 0; i < sizeOfPattern; i++)
        lps[i] = 0;

    int i = 0, j = 1;

    char pivot = pat[i];

    while (j < sizeOfPattern)
    {
        if (pat[i] == pat[j])
        {
            lps[j] = lps[j - 1] + 1;
            i += 1;
        }
        else if (pat[i - 1] == pat[j])
            lps[j] = lps[j - 1];
        else
            i = 0;

        j += 1;
    }

    i = 0; 
    j = 0;

    while(i < sizeOfString){

        if(j == sizeOfPattern - 1){
            cout<<"Found "<<(i - j)<<"\n";
            j = lps[j - 1];
        }

        if(txt[i] == pat[j]){
            j += 1;
            i += 1;
        }
        else{
            if(j)
                j = lps[j - 1];
            else
                i += 1;
        }
    }

}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    knuth_moris_pratt_soln(pattern, text);
}