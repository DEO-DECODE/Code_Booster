#include <bits/stdc++.h>
using namespace std;
// Minimum Cost to Make at Least One Valid Path in a Grid(LeetCode)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int moves[4] = {3, 4, 1, 2};
const int inf = 1e9;
int minCost(vector<vector<int>> &grid)
{
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> vis(m, vector<int>(n, 0)), costToReach(m, vector<int>(n, inf));
	set<pair<int, pair<int, int>>> st;
	costToReach[0][0] = 0;
	st.insert({0, {0, 0}});
	while (st.size() > 0)
	{
		auto currNode = (*st.begin());
		st.erase(st.begin());
		auto currCost = currNode.first;
		auto currX = currNode.second.first;
		auto currY = currNode.second.second;
		if (vis[currX][currY])
			continue;
		vis[currX][currY] = 1;
		for (int i = 0; i < 4; ++i)
		{
			int childX = currX + dx[i];
			int childY = currY + dy[i];
			int penalty = 1;
			if (grid[currX][currY] == moves[i])
				penalty = 0;
			if (childX >= 0 && childX < m && childY >= 0 && childY < n)
			{
				if (costToReach[childX][childY] > currCost + penalty)
				{
					costToReach[childX][childY] = costToReach[currX][currY] + penalty;
					st.insert({currCost + penalty, {childX, childY}});
				}
			}
		}
	}
	if(costToReach[m-1][n-1]==inf) return -1;
	return costToReach[m-1][n-1];
}
