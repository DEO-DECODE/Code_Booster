#include <bits/stdc++.h>
using namespace std;
// All Ancestors of a Node in a Directed Acyclic Graph(LeetCode)
vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{
	vector<vector<int>> adj(n);
	vector<int> indeg(n, 0);
	for (auto vec : edges)
	{
		adj[vec[0]].push_back(vec[1]);
		indeg[vec[1]]++;
	}
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (indeg[i] == 0)
		{
			q.push(i);
		}
	}
	unordered_map<int, set<int>> mp;
	while (q.size() > 0)
	{
		int currv = q.front();
		q.pop();
		for (auto child : adj[currv])
		{
			if (--indeg[child] == 0)
			{
				q.push(child);
			}
			mp[child].insert(currv);
			for (auto gp : mp[currv])
			{
				mp[child].insert(gp);
			}
		}
	}
	vector<vector<int>> ans(n);
	for (int i = 0; i < n; ++i)
	{
		for (auto child : mp[i])
		{
			ans[i].push_back(child);
		}
	}
	return ans;
}
