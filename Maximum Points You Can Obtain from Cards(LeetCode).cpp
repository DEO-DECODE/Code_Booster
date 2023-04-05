#include <bits/stdc++.h>
using namespace std;
// Maximum Points You Can Obtain from Cards(LeetCode)
int maxScore(vector<int> &cardPoints, int k)
{
	int n = cardPoints.size();
	int slidingWindowLength = cardPoints.size() - k;
	int ans = INT_MAX, sm = 0;
	for (int i = 0; i < slidingWindowLength; ++i)
	{
		sm += cardPoints[i];
	}
	int j = slidingWindowLength;
	while (j < n)
	{
		ans = min(ans, sm);
		// Acquire
		sm += cardPoints[j];
		// Release
		sm -= cardPoints[j - slidingWindowLength];
		j++;
	}
	ans = min(ans, sm);
	int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
	return totalSum - ans;
}
