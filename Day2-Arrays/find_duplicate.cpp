/*
 *
 *
Problem Statement:
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
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
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        // Find 1st collision
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Re-initialize fast pointer
        fast = nums[0];

        // Find 2nd collision
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
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
    int duplicate = solution.findDuplicate(nums);

    cout << duplicate;

    return 0;
}