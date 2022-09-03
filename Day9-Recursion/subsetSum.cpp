/*
 *
 *
Problem Statement:
Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

Example 1:

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8


Input: N=3,arr[]= {3,1,2}

Output: 0,1,2,3,3,4,5,6

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6

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
    vector<int> subsetSum(vector<int> &num)
    {
        int sum = 0;
        int n = num.size();
        vector<int> ds;
        calculateSum(num, ds, sum, 0, n);
        sort(ds.begin(), ds.end());
        return ds;
    }

    void calculateSum(vector<int> &num, vector<int> &ds, int sum, int index, int n)
    {
        if (index >= n)
        {
            ds.push_back(sum);
            return;
        }
        sum += num[index];
        calculateSum(num, ds, sum, index + 1, n);
        sum -= num[index];
        calculateSum(num, ds, sum, index + 1, n);
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> num(N);

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    Solution solution;
    vector<int> ans = solution.subsetSum(num);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}