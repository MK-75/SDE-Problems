/*
 *
 *
Problem Statement:
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

 *
 *
 */

#include<iostream>

using namespace std;

class Solution
{
public:
    int n = 0;
    int st = 0, end = n-1;
    int max_len = 1; // Max length of the palindrome

    string longestPalindrome(string s) {
        n = s.length();
        // If string is of length 1 or less
        if(n <= 1)
            return s;
        
        //Check for Odd length palindromes
        for(int i=0; i<n; i++) {
            checkPalindrome(s, i, i);
        }
        
        //Check for Even length palindromes
        for(int i=0; i<n; i++) {
            checkPalindrome(s, i, i+1);
        }

        return s.substr(st, max_len);
    }

    void checkPalindrome(string &s, int lo, int hi) {
        while(lo >= 0 && hi < n) {
            if(s[lo] == s[hi]) {
                lo--;
                hi++;
            } else
                break;
        }
        int len = hi-lo-1;
        if(len > max_len) {
            max_len = len;
            st = lo + 1;
            end = hi - 1;
        }
    }
};


int main() {
    string s;
    cin >> s;

    Solution solution;
    string longest_palindrome = solution.longestPalindrome(s);

    cout << longest_palindrome;
    return 0;
}