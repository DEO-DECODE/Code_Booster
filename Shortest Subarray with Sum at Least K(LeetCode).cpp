// Shortest Subarray with Sum at Least K(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int shortestSubarray(vector<int> &nums, int k)
{
    deque<pair<long, long>> dq;
    int n = nums.size();
    long long sm = 0, ans = INT_MAX;
    for (long long i = 0; i < n; ++i)
    {
        sm += (nums[i]);
        if (sm >= k)
        {
            ans = min(ans, i + 1);
        }
        pair<long long, long long> curr = {1e9, 1e9};
        while (!dq.empty() && (sm - dq.front().first >= k))
        {
            curr = dq.front();
            dq.pop_front();
            ans = min(ans, i - curr.second);
        }
        //
        while (!dq.empty() && sm <= dq.back().first)
        {
            dq.pop_back();
        }
        dq.push_back({sm, i});
    }
    return ans==INT_MAX?-1:ans;
}
