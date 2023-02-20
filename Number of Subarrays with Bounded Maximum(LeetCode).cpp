#include <bits/stdc++.h>
using namespace std;
// Number of Subarrays with Bounded Maximum(LeetCode)
int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
{
    int end = -1, start = -1, result = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > right)
        {
            start = i;
            end=i;
        }
        if (nums[i] >= left && nums[i] <= right)
        {
            end = i;
        }
        result += end - start;
    }
    return result;
}
