//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// Merge Intervals(LeetCode)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
	sort(intervals.begin(), intervals.end());
	int starti=intervals[0][0], endi=intervals[0][1];
	int i=0, n=intervals.size();
	vector<vector<int>> ans;
	while (i<n)
	{
		if(intervals[i][0]>endi){
			ans.push_back({starti, endi});
			starti=intervals[i][0];
			endi=intervals[i][1];
		}
		else{
			endi=max(endi, intervals[i][1]);
		}
		i++;
	}
	ans.push_back({starti, endi});
	return ans;
	
}
