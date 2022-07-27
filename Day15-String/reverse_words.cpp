/*
 *
 *
Problem Statement:
Given a string s, reverse the words of the string.

Examples:

Example 1:
Input: s=”this is an amazing program”
Output: “program amazing an is this”

Example 2:
Input: s=”This is decent”
Output: “decent is This”

 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        string word = "";
        string res = "";

        while (left <= right)
        {
            if (s[left] != ' ')
            {
                word += s[left];
            }
            else if (s[left] == ' ')
            {
                if (res != "")
                {
                    res = word + " " + res;
                }
                else
                    res = word;
                word = "";
            }
            left++;
        }

        if (word != "")
        {
            if (res != "")
            {
                res = word + " " + res;
            }
            else
                res = word;
        }

        return res;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution solution;
    string reverse_s = solution.reverseWords(s);

    cout << reverse_s;
    return 0;
}
