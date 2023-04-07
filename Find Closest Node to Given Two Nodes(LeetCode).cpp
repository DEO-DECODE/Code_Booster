#include <bits/stdc++.h>
using namespace std;
// Find Closest Node to Given Two Nodes(LeetCode)
vector<int> bfs(vector<int> adj[], int vertex, int n)
{
	queue<int> q;
	q.push(vertex);
	vector<int> dis(n, -1);
	q.push(vertex);
	dis[vertex] = 0;
	while (q.size() > 0)
	{
		int currv = q.front();
		q.pop();
		for (auto child : adj[currv])
		{
			if (dis[child] == -1)
			{
				dis[child] = dis[currv] + 1;
				q.push(child);
			}
		}
	}
	return dis;
}
int closestMeetingNode(vector<int> &edges, int node1, int node2)
{
	int n = edges.size();
	vector<int> adj[n];
	for (int i = 0; i < n; ++i)
	{
		if (edges[i] != -1)
		{
			adj[i].push_back(edges[i]);
		}
	}
	vector<int> dis1 = bfs(adj, node1, n);
	vector<int> dis2 = bfs(adj, node2, n);
	int minDist = INT_MAX, node = -1;
	for (int i = 0; i < n; ++i)
	{
		if (dis1[i] == -1 || dis2[i] == -1)
			continue;
		else
		{
			if (minDist > max(dis1[i], dis2[i]))
			{
				minDist = max(dis1[i], dis2[i]);
				node = i;
			}
		}
	}
	return node;
}
