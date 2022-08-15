/*
 *
 *
Problem Statement:
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

 *
 *
 */

#include <iostream>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0)
            nn = nn * -1;

        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn / 2;
            }
        }

        if (n < 0)
            ans = (double)(1.0) / ans;

        return ans;
    }
};

int main()
{
    double x;
    cin >> x;
    int n;
    cin >> n;

    Solution solution;
    double ans = solution.myPow(x, n);

    cout << ans;

    return 0;
}