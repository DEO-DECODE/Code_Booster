#include <bits/stdc++.h>
using namespace std;
// Corporate Flight Bookings(LeetCode)
vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
	vector<int> ans(n,0);
	for(auto vec: bookings){
		int startIndex=vec[0]-1, endingIndex=vec[1];
		ans[startIndex]+=vec[2];
		if(endingIndex!=n){
			ans[endingIndex]-=vec[2];
		}
	}
	for(int i=1; i<n; ++i){
		ans[i]+=ans[i-1];
	}
	return ans;
}
