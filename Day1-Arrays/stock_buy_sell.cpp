/*
 *
 *
Problem Statement:
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0..

 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minimal = INT_MAX;
        int profit = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++)
        {
            // Get the minimal on the left side of current element
            if (prices[i] < minimal)
            {
                minimal = prices[i];
            }
            // Check if selling the stock results into profit
            else if (prices[i] - minimal > profit)
            {
                profit = prices[i] - minimal;
            }
        }

        return profit;
    }
};

int main()
{
    int N;
    cin >> N;

    vector<int> prices;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        prices.push_back(a);
    }

    Solution solution;
    int maxProfit = solution.maxProfit(prices);

    cout << maxProfit;

    return 0;
}