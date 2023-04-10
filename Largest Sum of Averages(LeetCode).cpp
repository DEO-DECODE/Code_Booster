#include <bits/stdc++.h>
using namespace std;
// Largest Sum of Averages(LeetCode)
double func(int ind, vector<int> &nums, int k, int n, vector<vector<double>> &dp)
{
	if (k <= 0)
		return 0;
	if (dp[ind][k] != -1)
		return dp[ind][k];
	double sm = 0, ans = 0;
	for (int i = ind; i < n; ++i)
	{
		sm += nums[i];
		if (k != 1|| i == nums.size() - 1)
		{
			ans = max(ans, ((double)sm / (i - ind + 1) + func(i + 1, nums, k - 1, n, dp)));
		}
	}
	return dp[ind][k] = ans;
}
double largestSumOfAverages(vector<int> &nums, int k)
{
	int n = nums.size();
	vector<vector<double>> dp(n, vector<double>(k + 1, -1));
	return func(0, nums, k, n, dp);
}
int main()
{
	vector<int> nums = {9, 1, 2, 3, 9};
	cout << largestSumOfAverages(nums, 3);
}
