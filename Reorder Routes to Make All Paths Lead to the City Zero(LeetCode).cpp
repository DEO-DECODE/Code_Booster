#include <bits/stdc++.h>
using namespace std;
// Reorder Routes to Make All Paths Lead to the City Zero(LeetCode)
int minReorder(int n, vector<vector<int>> &connections)
{
	vector<pair<int, int>> adj[n];
	for (auto vec : connections)
	{
		adj[vec[0]].push_back({vec[1], 0});
		adj[vec[1]].push_back({vec[0], 1});
	}
	queue<int> q;
	vector<int> vis(n, 0);
	q.push(0);
	vis[0] = 1;
	int cost = 0;
	while (q.size() > 0)
	{
		auto currv = q.front();
		q.pop();
		for (auto childPair : adj[currv])
		{
			int childNode = childPair.first;
			if (vis[childNode] == 0)
			{
				cost += childPair.second;
				q.push(childNode);
				vis[childNode] = 1;
			}
		}
	}
	return n - 1 - cost;
}
