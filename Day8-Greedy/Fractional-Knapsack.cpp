/*
 *
 *
Problem Statement:
You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.
Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.
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
    double maximumValue(vector<pair<int, int>> &items, int n, int w)
    {
        double max_profit = 0.0;

        // Sort items by value to weight ratio
        sort(items.begin(), items.end(),
             [](pair<int, int> &a, pair<int, int> &b)
             {
                 double r1 = (double)a.second / (double)a.first;
                 double r2 = (double)b.second / (double)b.first;
                 return r1 > r2;
             });

        for (auto item : items)
        {
            if (item.first <= w)
            {
                w -= item.first;
                max_profit += item.second;
            }
            else
            {
                double vl = (double)(item.second * w) / (double)item.first;
                max_profit += vl;
                break;
            }
        }

        return max_profit;
    }
};

int main()
{
    int n, w;
    cin >> n >> w;

    vector<int> weights;
    vector<int> values;
    vector<pair<int, int>> items;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        weights.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        values.push_back(b);
    }

    for (int i = 0; i < n; i++)
    {
        items.push_back({weights[i], values[i]});
    }

    Solution solution;
    double ans = solution.maximumValue(items, n, w);

    cout << ans;
    return 0;
}