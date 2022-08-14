/*
 *
 *
Problem Statement:
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

 *
 *
 */

#include <iostream>
#include <vector>
#define ll long long

using namespace std;

class Solution
{
public:
    vector<int> missing_repeated_number(const vector<int> &nums)
    {
        ll len = nums.size();
        vector<int> ans;
        ll missing_number = 0, repeating = 0;
        ll S = (len * (len + 1)) / 2;                 // Sum of first N integers
        ll P = (len * (len + 1) * (2 * len + 1)) / 6; // Sum of squares of first N integer

        for (int i = 0; i < len; i++)
        {
            S -= (ll)nums[i];               // Calculate S = X - Y
            P -= (ll)nums[i] * (ll)nums[i]; // Calculate P = X^2 - Y^2
        }

        missing_number = (S + P / S) / 2;
        repeating = missing_number - S;

        ans.push_back(missing_number);
        ans.push_back(repeating);

        return ans;
    }
};

int main()
{
    int N;
    cin >> N;

    vector<int> nums;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    Solution solution;
    vector<int> ans = solution.missing_repeated_number(nums);

    cout << "Missing number: " << ans[0] << " Repeating number: " << ans[1];

    return 0;
}