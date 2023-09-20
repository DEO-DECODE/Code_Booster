#include <bits/stdc++.h>
using namespace std;
// Single-Threaded CPU(LeetCode)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  int n = tasks.size();
  for (int i = 0; i < n; ++i)
  {
    tasks[i].push_back(i);
  }
  vector<int> ans;
  sort(tasks.begin(), tasks.end());
  int curTime = tasks[0][0];
  int ind = 0;
  while (ind < n)
  {
      while (ind < n && tasks[ind][0] <= curTime)
    {
      pq.push({tasks[ind][1], tasks[ind][2], tasks[ind][0]});
      // processing time, enque, indexing
      ind++;
    }
    if (pq.empty() && ind < n)
    {
      curTime = tasks[ind][0];
    }
    else
    {
      auto vec = pq.top();
      pq.pop();
      curTime += vec[0];
      ans.push_back(vec[1]);
    }
  }
  while (pq.size())
  {
    auto vec = pq.top();
    pq.pop();
    ans.push_back(vec[1]);
  }
  return ans;
    }
};
