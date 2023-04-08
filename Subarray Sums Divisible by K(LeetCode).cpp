#include <bits/stdc++.h>
using namespace std;
// Subarray Sums Divisible by K(LeetCode)
int subarraysDivByK(vector<int> &nums, int k)
{
	unordered_map<int, int> mp;
	int i = 0, n = nums.size(), sm = 0;
	int ans = 0;
	mp[0] = 1;
	while (i < n)
	{
		sm += nums[i];
		int rem = sm % k;
		if (rem < 0)
			rem += k;
		if (mp[rem] > 0)
		{
			ans += mp[rem];
		}
		mp[rem]++;
		i++;
	}
	return ans;
}
