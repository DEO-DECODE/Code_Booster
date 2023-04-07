#include <bits/stdc++.h>
using namespace std;
// Shortest Path with Alternating Colors(LeetCode)
vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
	vector<int> dis(n, -1);
	// redEdge -> -2 blueEdge -> -3
	vector<pair<int, int>> adj[n+1];
	for (auto vec : redEdges)
	{
		adj[vec[0]].push_back({vec[1], -2});
	}
	for (auto vec : blueEdges)
	{
		adj[vec[0]].push_back({vec[1], -3});
	}
	queue<vector<int>> q;
	q.push({0, 0, -1});
	// currNode dis color
	while (q.size() > 0)
	{
		auto currVec = q.front();
		q.pop();
		int parentEdgeColor = currVec[2];
		int currNode = currVec[0];
		if (dis[currVec[0]] == -1)
		{
			dis[currVec[0]] = currVec[1];
		}
		for (auto &pairChild : adj[currNode])
		{
			int childVertex = pairChild.first;
			int childVertexColor = pairChild.second;
			if (childVertex != -1 && (parentEdgeColor != childVertexColor))
			{
				q.push({childVertex, currVec[1] + 1, childVertexColor});
				pairChild.first = -1;
			}
		}
	}
	return dis;
}
