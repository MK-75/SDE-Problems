/*
 *
 *
Problem Statement:

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int element = 0;

        for (auto i : nums)
        {
            if (count == 0)
                element = i;
            if (element == i)
                count++;
            else
                count--;
        }

        return element;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    Solution solution;
    int majority = solution.majorityElement(nums);

    cout << majority;
    return 0;
}