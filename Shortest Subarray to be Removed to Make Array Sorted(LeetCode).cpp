#include <bits/stdc++.h>
using namespace std;
// Shortest Subarray to be Removed to Make Array Sorted(LeetCode)
int findLengthOfShortestSubarray(vector<int> &arr)
{
    int lo = 0, hi = arr.size() - 1, n = arr.size();
    while ((lo + 1 < n) && (arr[lo] <= arr[lo + 1]))
    {
        lo++;
    }
    if (lo == n - 1)
        return 0;
    while ((hi >= lo) && (arr[hi] >= arr[hi - 1]))
    {
        hi--;
    }
    if (hi == 0)
        return n - 1;
    int ans = min(n - 1 - lo, hi);
    int i = 0, j = hi;
    while (i <= lo && j < n)
    {
        if (arr[i] <= arr[j])
        {
            ans = min(ans, j - i - 1);
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
