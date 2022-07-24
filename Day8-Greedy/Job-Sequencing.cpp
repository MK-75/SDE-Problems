/*
 *
 *
Problem Statement:
You are given a N x 2 2-D array 'Jobs' of 'N' jobs where Jobs[i][0] denote the deadline of i-th job and Jobs[i][1] denotes the profit associated with i-th job.
You will make a certain profit if you complete the job within the deadline associated with it. Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.
Your task is to find out the maximum profit that you can make.
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
    int jobScheduling(vector<vector<int>> &jobs)
    {
        int max_profit = 0;
        vector<int> deadline = jobs[0];
        vector<int> profit = jobs[1];

        int n = deadline.size();

        vector<pair<int, int>> jb;

        // make pair of deadline and job so it beacomes easire to sort
        for (int i = 0; i < n; i++)
        {
            jb.push_back({deadline[i], profit[i]});
        }

        int t = *max_element(deadline.begin(), deadline.end());
        vector<int> timeline(t + 1, -1);

        // sort according to the profit
        sort(jb.begin(), jb.end(),
             [](const pair<int, int> &x, pair<int, int> &y)
             {
                 if (x.second != y.second)
                 {
                     return x.second > y.second;
                 }
                 return x.first > y.first;
             });

        for (int i = 0; i < n; i++)
        {
            int dl = jb[i].first;
            int p = jb[i].second;
            // Do the job on the last day(deadline day) or on any previous day before its deadline
            for (int j = dl; j > 0; j--)
            {
                if (timeline[j] == -1)
                {
                    timeline[j] = p;
                    max_profit += p;
                    break;
                }
            }
        }

        return max_profit;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> deadline;
    vector<int> profit;
    vector<vector<int>> jobs;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        deadline.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        profit.push_back(b);
    }

    jobs.push_back(deadline);
    jobs.push_back(profit);

    Solution solution;
    int ans = solution.jobScheduling(jobs);

    cout << ans;

    return 0;
}