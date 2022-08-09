/*
 *
 *
Problem Statement:
Given an integer numRows, return the first numRows of Pascal's triangle.

 *
 *
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> pascalTriangle(numRows);

            // Set the first element in the first row to 1
            pascalTriangle[0] = vector<int>({1});

            for(int row = 1; row < numRows; row++) {
                pascalTriangle[row] = vector<int> (row + 1);

                for(int col=0; col <= row; col++) {
                    pascalTriangle[row][col] = 0;
                    pascalTriangle[row][col] += col < row ? pascalTriangle[row-1][col] : 0;     // Copy every element from the above row
                    pascalTriangle[row][col] += col > 0 ? pascalTriangle[row-1][col-1] : 0;     // Add element from previous row and col
                }
            }
            return pascalTriangle;
        }
};

int main() {
    int numRows;
    cin >> numRows;

    Solution solution;
    vector<vector<int>> pascalTriangle = solution.generate(numRows);

    for(int i=0; i<numRows; i++) {
        for(int j=0; j<pascalTriangle[i].size(); j++) {
            cout << pascalTriangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}