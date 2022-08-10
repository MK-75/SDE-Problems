/*
 *
 *
Problem Statement:
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        // Using Dutch National Flag algorithm
        int lo = 0, mid = 0, hi = n - 1;

        // Keep 0's on left of lo and 2's on right of his
        while (mid <= hi)
        {
            switch (nums[mid])
            {
            // If element is 0
            case 0:
                swap(nums[lo++], nums[mid++]);
                break;
            // If element is 1
            case 1:
                mid++;
                break;
            // If element is 2
            case 2:
                swap(nums[mid], nums[hi--]);
                break;
            }
        }
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
    solution.sortColors(nums);

    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}