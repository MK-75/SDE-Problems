/*
 *
 *
Problem Statement:
Given a roman numeral, convert it to an integer.

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4

 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lookup(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }

    int romanToInt(string s)
    {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            int vl = lookup(c);

            if (i + 1 < n && vl < lookup(s[i + 1]))
            {
                sum -= vl;
            }
            else
            {
                sum += vl;
            }
        }

        return sum;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution solution;
    int ans = solution.romanToInt(s);

    cout << ans;
    return 0;
}