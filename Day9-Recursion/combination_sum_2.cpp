/*
 *
 *
Problem Statement:
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

 *
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    void calculate(vector<int>& candidates, int target, int index, vector<int> &currComb, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(currComb);
            return;
        }
        
        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            currComb.push_back(candidates[i]);
            calculate(candidates, target - candidates[i], i + 1, currComb, ans);
            currComb.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;   
        sort(candidates.begin(), candidates.end());
        
        calculate(candidates, target, 0, currComb, ans);
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
    vector<vector<int>> ans = solution.combinationSum2(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}