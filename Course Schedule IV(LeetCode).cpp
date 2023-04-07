#include <bits/stdc++.h>
using namespace std;
// Course Schedule IV(LeetCode)
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
{
	vector<int> adj[numCourses];
	vector<int> indeg(numCourses, 0);
	queue<int> q;
	vector<vector<bool>> orderOfCourse(numCourses, vector<bool>(numCourses, false));
	vector<int> inDeg(numCourses, 0);
	vector<bool> ans;
	for (auto vec : prerequisites)
	{
		adj[vec[0]].push_back(vec[1]);
		indeg[vec[1]]++;
	}
	for (int i = 0; i < numCourses; ++i)
	{
		if (indeg[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size() > 0)
	{
		int currCourse = q.front();
		q.pop();
		for (auto child : adj[currCourse])
		{
			orderOfCourse[currCourse][child] = true;
			for(int i=0; i<numCourses; ++i){
				if(orderOfCourse[i][currCourse]==1){
					orderOfCourse[i][child]=true;
				}
			}
			if (--indeg[child] == 0)
			{
				q.push(child);
			}
		}
	}
	for (int i=0; i<queries.size(); ++i)
	{
		ans.push_back(orderOfCourse[queries[i][0]][queries[i][1]]);
	}
	return ans;
}
