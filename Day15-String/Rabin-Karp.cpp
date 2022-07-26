/*
 *
 *
Problem Statement:
You are given a string ‘str’ of length 'N' and a string ‘pat’ of length 'M'. Your task is to find the starting index of all the occurrences of ‘pat’ in str.
You need to return a list of integers that denote the indices from which ‘pat’ is present in ‘str’(consider 0 based indexing).
For example,
Let str= “AABAACAADAABAABA”
And pat= “AABA”
We will return the array/list [0,9,12] as we can clearly see that from indices 0 9 and 12 we have the same pattern ‘pat’ in ‘str’


===========================================================
Hash used in Rabin-Karp:

hash(txt[s+1...s+m]) = (d * (hash(txt[s....s=m-1]) - txt[s] * h) + txt[s+m] ) % q
hash( txt[s .. s+m-1] ) : Previous hash value.
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1)
d: Number of characters in the alphabet (256)
q: A prime number
h: d^(m-1)

===========================================================

How does the above expression work?

This is simple mathematics, we compute decimal value of current window from previous window.
For example pattern length is 3 and string is “23456”
You compute the value of first window (which is “234”) as 234.
How  will you compute value of next window “345”? You will do (234 – 2*100)*10 + 5 and get 345.

===========================================================
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> stringMatch(string &str, string &pat)
    {
        vector<int> res;
        int m = pat.size();
        int n = str.size();
        int d = 256;
        int q = INT_MAX;
        int h = 1;
        int pat_hash = 0; // Hash value of the pattern
        int str_hash = 0; // Hash value of th text in window

        // Calculate h = pow(d, m-1)
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // Calculate hash for the pattern and first window
        for (int i = 0; i < m; i++)
        {
            pat_hash = (d * pat_hash + pat[i]) % q;
            str_hash = (d * str_hash + str[i]) % q;
        }

        int j = 0, i = 0;

        for (i = 0; i <= n - m; i++)
        {
            cout << "i= " << i << " Hash: " << str_hash << endl;
            if (pat_hash == str_hash)
            {
                for (j = 0; j < m; j++)
                {
                    if (str[i + j] != pat[j])
                        break;
                }
                if (j == m)
                {
                    res.push_back(i);
                }
            }
            if (i < n - m)
            {
                str_hash = (d * (str_hash - str[i] * h) + str[i + m]) % q;
                if (str_hash < 0)
                    str_hash %= q;
            }
        }
        return res;
    }
};

int main()
{
    string str, pat;
    cin >> str >> pat;

    Solution solution;
    vector<int> res = solution.stringMatch(str, pat);

    for(int i=0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}