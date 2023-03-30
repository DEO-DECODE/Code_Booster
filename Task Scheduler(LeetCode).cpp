//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// Task Scheduler(LeetCode)
int leastInterval(vector<char> &tasks, int n)
{
	unordered_map<char, int> taskFreq;
	for (auto ch : tasks)
	{
		taskFreq[ch]++;
	}
	priority_queue<pair<int, char>> pq;
	int cnt = 0;
	for(auto val: taskFreq){
		pq.push({val.second, val.first});
	}
	while (pq.size() > 0)
	{
		vector<pair<int, char>> stillRemTask;
		int cpuTime = n + 1;
		while (cpuTime && !pq.empty())
		{
			auto pr = pq.top();
			pq.pop();
			int freq = pr.first;
			if (--freq)
			{
				stillRemTask.push_back({freq, pr.second});
			}
			cpuTime--;
			cnt++;
		}
		for (auto pr : stillRemTask)
		{
			pq.push(pr);
		}
		if (pq.empty())
			break;
		cnt += cpuTime;
	}
	return cnt;
}
