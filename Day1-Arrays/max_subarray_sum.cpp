/*
 *
 *
Problem Statement:
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;  // max subarray sum till ith element in the array
        int sum = 0;        // subarray sum of all elements till ith element in the array

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            maxi = max(sum, maxi);
            if (sum < 0)
                sum = 0;
        }

        return maxi;
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
    int max_sum = solution.maxSubArray(nums);

    cout << max_sum;

    return 0;
}