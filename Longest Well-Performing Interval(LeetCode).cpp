#include <bits/stdc++.h>
using namespace std;
// Longest Well-Performing Interval(LeetCode)
int longestWPI(vector<int> &hours)
{
	int sm = 0, n = hours.size(), j = 0, ans = 0;
	unordered_map<int, int> firstOccurence;
	// firstOccurence[0] = -1;
	for (int i = 0; i < n; ++i)
	{
		int val = hours[i];
		val > 8 ? val = 1 : val = -1;
		sm += val;
		if (sm > 0)
			ans = max(ans, i + 1);
		else
		{
			if (firstOccurence.count(sm - 1))
			{
				ans = max(ans, i - firstOccurence[sm-1]);
			}

			if (firstOccurence.find(sm) == firstOccurence.end())
			{
				// First time;
				firstOccurence[sm] = i;
			}
		}
	}

	return ans;
}
