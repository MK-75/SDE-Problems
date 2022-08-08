/*
 *
 *
Problem Statement:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeros(vector<vector<int>> &matrix)
    {
        int m = matrix.size();          // Row length
        int n = matrix[0].size();       // Column length
        bool col1 = 1;                  // Bool var to check if 1st col should be set to zero or not

        for (int i = 0; i < m; i++)
        {
            // If 1st col is zero set col1 to zero as we will make entire 1st col zero
            if (matrix[i][0] == 0)
                col1 = 0;
            for (int j = 1; j < n; j++)
            {
                // If zero is found in any cell mark first element in its row 0 and first element in its col 0
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Traverse matrix in reverse direction
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 1; j--)
            {
                // Set a cell to zero if first element in its row is zero OR first element in its column is zero
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
            // We make 1st element of row 0 if col1 is 0
            if (col1 == 0)
                matrix[i][0] = 0;
        }
    }
};

int main()
{
    int N, M;
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a;
            cin >> matrix[i][j];
        }
    }

    Solution solution;
    solution.setZeros(matrix);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}