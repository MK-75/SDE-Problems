/*
 *
 *
Problem Statement:
Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array?
Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Example 1:

Input Format: N = 5, array[] = {1,2,3,4,5}

Result: 0

Explanation: we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. More clear example: 2 has index 1
and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an
inversion.

 *
 *
 */

#include <iostream>
#include <vector>
#define ll long long

using namespace std;

class Solution
{
public:
    ll merge(ll *arr, ll *temp, ll lo, ll mid, ll hi)
    {
        ll i = lo, j = mid;
        ll inv_count = 0;
        ll k = lo;

        while (i <= mid - 1 && j <= hi)
        {
            if (arr[i] < arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                inv_count += mid - i;
            }
        }

        while (i <= mid - 1)
            temp[k++] = arr[i++];

        while (j <= hi)
            temp[k++] = arr[j++];

        for (i = lo; i <= hi; i++)
            arr[i] = temp[i];

        return inv_count;
    }

    ll merge_sort(ll *arr, ll *temp, ll lo, ll hi)
    {
        ll inv_count = 0, mid = 0;
        if (lo < hi)
        {
            mid = (lo + hi) / 2;
            inv_count += merge_sort(arr, temp, lo, mid);        // Create partitions from left to mid
            inv_count += merge_sort(arr, temp, mid + 1, hi);    // Create partitions from mid to right
            inv_count += merge(arr, temp, lo, mid + 1, hi);     // Merge the partitions
        }
        return inv_count;
    }
};

int main()
{
    int N;
    cin >> N;

    ll nums[N];
    ll temp[N];
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    Solution solution;
    ll ans = solution.merge_sort(nums, temp, 0, N - 1);

    cout << ans;
    return 0;
}