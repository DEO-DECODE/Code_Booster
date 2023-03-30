#include <bits/stdc++.h>
using namespace std;
// Subarray Product Less Than K(LeetCode)
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
	int i=0, j=0, n=nums.size(), prod=1, ans=0;
	while (i<n)
	{
		prod*=nums[i];
		while (prod>=k&&j<=i)
		{
			prod=prod/nums[j];
			j++;
		}
		ans+=(i-j+1);
	}
	return ans;
}
