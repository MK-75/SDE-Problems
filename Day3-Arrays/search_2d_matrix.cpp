/*
 *
 *
Problem Statement:
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;

        int M = matrix.size();
        int N = matrix[0].size();

        int lo = 0, hi = (N * M) - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / N][mid % N] == target)
                return true;
            if (matrix[mid / N][mid % N] < target)
                lo = mid + 1;
            else
            {
                hi = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    int N, M;
    int target;
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cin >> target;

    Solution solution;
    bool ans = solution.searchMatrix(matrix, target);

    if (ans)
    {
        cout << "Target found!";
    }
    else
    {
        cout << "Target NOT found!";
    }

    return 0;
}