#include <bits/stdc++.h>
using namespace std;
// Maximal Network Rank(LeetCode)
int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
	map<int, set<int>> mp;
	for (auto vec : roads)
	{
		mp[vec[0]].insert(vec[1]);
		mp[vec[1]].insert(vec[0]);
	}
	int maxm = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int nbr1 = mp[i].size(), nbr2 = mp[j].size();
			auto itr = mp[i].find(j);
			if (itr != mp[i].end())
				nbr1--;
			maxm = max(maxm, nbr1 + nbr2);
		}
	}
	return maxm;
}
