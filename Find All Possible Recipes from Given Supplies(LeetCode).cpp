#include <bits/stdc++.h>
using namespace std;
//(LeetCode)Find All Possible Recipes from Given Supplies

vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
{
	unordered_map<string, int> inDeg;
	queue<string> q;
	vector<string> ans;
	unordered_map<string, vector<string>> adj;
	for (auto str : supplies)
	{
		q.push(str);
	}
	for (int i = 0; i < ingredients.size(); ++i)
	{
		for (auto req : ingredients[i])
		{
			adj[req].push_back(recipes[i]);
			inDeg[recipes[i]]++;
		}
	}
	while (q.size() > 0)
	{
		auto str = q.front();
		q.pop();
		if (find(recipes.begin(), recipes.end(), str) != recipes.end())
			ans.push_back(str);
		for (auto child : adj[str])
		{
			if (--inDeg[child] == 0)
			{
				q.push(child);
			}
		}
	}
	return ans;
}
