#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumMeetings(vector<int> &start, vector<int> &end)
    {
        int ans;
        vector<pair<int, int>> timings;
        int n = start.size();

        for (int i = 0; i < n; i++)
            timings.push_back({start[i], end[i]});

        // Sorting based on end time of meeting
        sort(timings.begin(), timings.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.second != b.second)
                 {
                     return a.second < b.second;
                 }
                 return a.first < b.first;
             });

        // We can accomodate atleast one meeting
        ans = 1;

        vector<pair<int, int>>::iterator itr;
        itr = timings.begin();
        int limit = itr->second; // Set limit to the end time of first meeting
        itr++;

        for (itr; itr != timings.end(); itr++)
        {
            // Start time of next meeting > End time of previous meeting
            if (itr->first > limit)
            {
                ans++;
                limit = itr->second;
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> start;
    vector<int> end;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        start.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        end.push_back(b);
    }

    Solution solution;
    int ans = solution.maximumMeetings(start, end);

    cout << ans;

    return 0;
}
