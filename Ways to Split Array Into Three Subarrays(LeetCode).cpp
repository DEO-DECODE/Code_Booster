#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// Ways to Split Array Into Three Subarrays(LeetCode).
int waysToSplit(vector<int> &nums)
{
    int cnt = 0, n = nums.size(), j = 0, k = 0;
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    /*
    1  2  2  2  5  0
    1  3  5  7 12 12
    */
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < n - 2; ++i)
    {
        if (j <= i)
            j = i + 1;
        while (j < n - 1 && prefixSum[i] > prefixSum[j] - prefixSum[i])
        {
            j++;
        }
        if (k < j)
            k = j;
        while (k < n - 1 && prefixSum[k] - prefixSum[i] <= prefixSum[n - 1] - prefixSum[k])
        {
            k++;
        }
        cnt = (cnt + k - j) % mod;
    }
    return cnt;
}
