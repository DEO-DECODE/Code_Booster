#include <bits/stdc++.h>
using namespace std;
// Count Number of Nice Subarrays(LeetCode)
int numberOfSubarrays(vector<int> &nums, int k)
{
	unordered_map<int, int> mp;
	int sm = 0, ans = 0;
	mp[0] = 1;
	for (int i = 0; i < nums.size(); ++i)
	{
		sm += nums[i] % 2;
		if (mp[sm - k] != 0)
		{
			ans += mp[sm - k];
		}
		mp[sm]++;
	}
	return ans;
}
