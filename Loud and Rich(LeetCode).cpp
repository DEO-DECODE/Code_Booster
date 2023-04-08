#include <bits/stdc++.h>
using namespace std;
// Loud and Rich(LeetCode)
vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
{
	int n = quiet.size();
	vector<int> adj[n];
	vector<int> indeg(n), ans(n);
	// Alignment: rich -> poor
	for (auto vec : richer)
	{
		adj[vec[0]].push_back(vec[1]);
		indeg[vec[1]]++;
	}
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		ans[i] = i;
		if (indeg[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size() > 0)
	{
		auto currNode = q.front();
		q.pop();
		for (auto child : adj[currNode])
		{
			if (quiet[ans[child]] > quiet[ans[currNode]])
			{
				ans[child] = ans[currNode];
			}
			if (--indeg[child] == 0)
			{
				q.push(child);
			}
		}
	}
	return ans;
}
