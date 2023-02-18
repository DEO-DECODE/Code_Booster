#include <bits/stdc++.h>
using namespace std;
//Max Consecutive Ones III(LeetCode)
int longestOnes(vector<int> &nums, int k)
{
    // Finding the max subArray with At most K 0s
    int n = nums.size(), ans1 = 0, ans2 = 0, j = 0;
    unordered_map<int, int> frq1;
    for (int i = 0; i < n; ++i)
    {
        frq1[nums[i]]++;
        while (frq1[0] > k)
        {
            frq1[nums[j]]--;
            j++;
        }
        ans1 = max(ans1, i - j + 1);
    }
    return ans1;
}
