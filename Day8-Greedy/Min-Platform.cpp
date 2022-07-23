#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int calculateMinPatforms(vector<int> &arr, vector<int> &dept, int n)
    {
        // Sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dept.begin(), dept.end());

        int platform = 1; // Atleat 1 platform will be occupied
        int max_platform = 1;
        int i = 1, j = 0;

        while (i < n && j < n)
        {
            // If a train is arriving before previous train departs we need one more platform
            if (arr[i] <= dept[j])
            {
                platform += 1;
                i++;
            }
            else
            {
                platform -= 1;
                j++;
            }
            max_platform = max(max_platform, platform);
        }
        return max_platform;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arrival, dept;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arrival.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        dept.push_back(b);
    }

    Solution solution;
    int ans = solution.calculateMinPatforms(arrival, dept, n);

    cout << ans;

    return 0;
}