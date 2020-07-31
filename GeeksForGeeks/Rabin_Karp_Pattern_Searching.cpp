#include <bits/stdc++.h>

using namespace std;

// d is the number of characters in the input alphabet
#define d 256

void rabin_karp_soln(string pattern, string text, int q)
{
    int sizeOfPattern = pattern.size();
    int sizeOfText = text.size();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (int i = 0; i < sizeOfPattern - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < sizeOfPattern; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= sizeOfText - sizeOfPattern; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if (p == t)
        {
            /* Check for characters one by one */
            for (j = 0; j < sizeOfPattern; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == sizeOfPattern)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < sizeOfText - sizeOfPattern)
        {
            t = (d * (t - text[i] * h) + text[i + sizeOfPattern]) % q;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    int q = 101; // A prime number  (Used for hashing: If greater will decrease collashing)
    rabin_karp_soln(pattern, text, q);
}