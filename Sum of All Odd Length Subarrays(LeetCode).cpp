#include <bits/stdc++.h>
using namespace std;
// Sum of All Odd Length Subarrays(LeetCode)
int sumOfSubArrays(int slidingWindowLendth, vector<int> &arr)
{
    int n = arr.size(), totalSum=0;
    int sm = 0, i = 0;
    for (i = 0; i < slidingWindowLendth; ++i)
    {
        sm += arr[i];
    }
    totalSum+=sm;
    while (i < n)
    {
        // Acquire
        sm += arr[i];
        // Release
        sm -= arr[i - slidingWindowLendth];
        totalSum+=sm;
        i++;
    }
    return totalSum;
}
int sumOddLengthSubarrays(vector<int> &arr)
{
    int ans = 0, sm;
    for (int k = 1; k <= arr.size(); k += 2)
    {
        sm = sumOfSubArrays(k, arr);
        // cout << sm << endl;
        ans += sm;
        // cout << ans << endl;
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 4, 2, 5, 3};
    cout << sumOddLengthSubarrays(arr);
}
