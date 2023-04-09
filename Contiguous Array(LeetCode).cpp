#include <bits/stdc++.h>
using namespace std;
// Contiguous Array(LeetCode)
int findMaxLength(vector<int> &nums)
{
	int n = nums.size(), sm = 0, ans=0;
	unordered_map<int, vector<int>> firstOcuurence;
	firstOcuurence[0] = {-1};
	for (int i = 0; i < n; ++i)
	{
		int val=nums[i];
		val==1?val=1:val=-1;
		sm+=val;
		if(firstOcuurence[sm].size()==0){
			firstOcuurence[sm]={i};
		}
		else{
			ans=max(ans, i-firstOcuurence[sm][0]);
		}
	}
	return ans;
}
