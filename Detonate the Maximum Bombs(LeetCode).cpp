#include <bits/stdc++.h>
using namespace std;
// Detonate the Maximum Bombs(LeetCode)
bool inRange(vector<vector<int>> &bombs, int i, int j)
{
	long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
	long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
	long long dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return dist <= (r1 * r1);
}
int bfs(vector<vector<int>> &graph, int vertex, int n)
{
	vector<int> vis(n, 0);
	queue<int> q;
	q.push(vertex);
	vis[vertex] = 1;
	int cnt = 0;
	while (q.size() > 0)
	{
		int sz = q.size();
		for (int i = 0; i < sz; i++)
		{
			int currv = q.front();
			q.pop();
			cnt++;
			for (auto child : graph[currv])
			{
				if (vis[child] == 0)
				{
					q.push(child);
					vis[child] = 1;
				}
			}
		}
	}
	return cnt;
}
int maximumDetonation(vector<vector<int>> &bombs)
{
	int n = bombs.size();
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			if (inRange(bombs, i, j))
			{
				graph[i].push_back(j);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, bfs(graph, i, n));
	}
	return ans;
}
