/*
 *
 *
Problem Statement:
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> merged;
        if (intervals.size() == 0)
            return merged;

        sort(intervals.begin(), intervals.end());
        vector<int> temp;
        temp = intervals[0];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= temp[1])
                temp[1] = max(temp[1], intervals[i][1]);
            else
            {
                merged.push_back(temp);
                temp = intervals[i];
            }
        }
        merged.push_back(temp);
        return merged;
    }
};

int main()
{
    int N, M;
    cin >> M >> N;

    vector<vector<int>> intervals(M, vector<int>(N));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> intervals[i][j];
        }
    }

    Solution solution;
    vector<vector<int>> merged = solution.merge(intervals);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << merged[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}