/*
 *
 *
Problem Statement:
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int index1 = -1, index2 = 0;

        if (n == 1)
            return;

        // Find the first breakpoint
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index1 = i;
                break;
            }
        }

        // If index1 < 0 it means elements are in decreasing order
        if (index1 < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            // Find 2nd breakpoint
            for (int i = n - 1; i > index1; i--)
            {
                if (nums[i] > nums[index1])
                {
                    index2 = i;
                    break;
                }
            }
            
            swap(nums[index1], nums[index2]);
            reverse(nums.begin() + index1 + 1, nums.end());
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
    solution.nextPermutation(nums);

    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}