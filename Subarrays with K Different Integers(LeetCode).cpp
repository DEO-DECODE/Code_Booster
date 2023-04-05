#include <bits/stdc++.h>
using namespace std;
// Subarrays with K Different Integers(LeetCode)
int func(vector<int> &nums, int k){
	if(k==0) return 0;
	int n=nums.size(), i=0, j=0, ans=0;
	unordered_map<int, int> freqCounter;
	for(i=0; i<n; ++i){
		freqCounter[nums[i]]++;
		while (j<i&&freqCounter.size()>k)
		{
			freqCounter[nums[j]]--;
			if(freqCounter[nums[j]]==0){
				freqCounter.erase(freqCounter.find(nums[j]));
			}
			j++;
		}
		ans+=(i-j+1);
	}
	return ans;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
	return func(nums, k)-func(nums, k-1);
}
