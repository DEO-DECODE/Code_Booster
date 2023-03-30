//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//  Minimum Number of Arrows to Burst Balloons(LeetCode)
int findMinArrowShots(vector<vector<int>> &points)
{
	sort(points.begin(), points.end());
	int i=0, n=points.size();
	int startingP=points[0][0], endingP=points[0][1];
	int cnt=1;
	while (i<n)
	{
		if(points[i][0]>endingP){
			startingP=points[i][0];
			endingP=points[i][1];
			cnt++;
		}
		else{
			startingP=max(startingP, points[i][0]);
			endingP=min(endingP, points[i][1]);
		}
		i++;
	}
	return cnt;
	
}
