/*
 *
 *
Problem Statement:
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

 *
 *
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    void calculate(vector<int> &nums, int target, int currSum, int index, vector<int> &currComb, vector<vector<int>> &ans) {
        if(currSum > target)
            return;
        if(currSum == target) {
            ans.push_back(currComb);
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            currComb.push_back(nums[i]);
            currSum += nums[i];
            calculate(nums, target, currSum, i, currComb, ans);
            currSum -= nums[i];
            currComb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> currComb;

        calculate(nums, target, 0, 0, currComb, ans);
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

    int target; cin >> target;

    Solution solution;
    vector<vector<int>> ans = solution.combinationSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}