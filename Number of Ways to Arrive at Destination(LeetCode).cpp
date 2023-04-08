#include <bits/stdc++.h>
using namespace std;
// Number of Ways to Arrive at Destination(LeetCode)
const int mod = 1e9 + 7;
const int inf = 1e12;
int countPaths(int n, vector<vector<int>> &roads)
{
	vector<pair<long long, long long>> adj[n];
	vector<long long> timeToReach(n, inf);
	vector<long long> numWays(n, 0);
	
	for (auto vec : roads)
	{
		adj[vec[0]].push_back({vec[1], vec[2]});
		adj[vec[1]].push_back({vec[0], vec[2]});
	}
	// u -> v int t minutes
	set<pair<long long, long long>> st;
	st.insert({0, 0});
	timeToReach[0]=0;
	numWays[0] = 1;
	while (st.size() > 0)
	{
		auto node = (*st.begin());
		st.erase(st.begin());
		long long currv = node.second, timeTaken = node.first;
		for (auto child : adj[currv])
		{
			int childNode = child.first, timeTakenToReachChildNode = child.second;
			if (timeToReach[childNode] > timeToReach[currv] + timeTakenToReachChildNode)
			{
				timeToReach[childNode] = timeToReach[currv] + timeTakenToReachChildNode;
				st.insert({timeToReach[childNode], childNode});
				numWays[childNode]=numWays[currv]%mod;
			}
			else if (timeToReach[childNode] == timeTaken + timeTakenToReachChildNode)
			{
				numWays[childNode] = (numWays[childNode] + numWays[currv]) % mod;
			}
		}
	}
	if (numWays[n - 1] == inf)
		return -1;
	return numWays[n - 1];
}
