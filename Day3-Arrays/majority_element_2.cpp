/*
 *
 *
Problem Statement:

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int count1 = 0, count2 = 0;
        int nums1 = -1, nums2 = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums1 == nums[i])
                count1++;
            else if (nums2 == nums[i])
                count2++;
            else if (count1 == 0)
            {
                nums1 = nums[i];
                count1++;
            }
            else if (count2 == 0)
            {
                nums2 = nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == nums1)
                count1++;
            else if (nums[i] == nums2)
                count2++;
        }

        if (count1 > n / 3)
            ans.push_back(nums1);
        if (count2 > n / 3)
            ans.push_back(nums2);

        return ans;
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
    vector<int> ans = solution.majorityElement(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}