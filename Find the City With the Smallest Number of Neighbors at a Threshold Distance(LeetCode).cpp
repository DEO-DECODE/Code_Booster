#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
// Find the City With the Smallest Number of Neighbors at a Threshold Distance(LeetCode)
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, inf));
        for (int i = 0; i < edges.size(); ++i)
        {
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (dist[i][k] != inf && dist[k][j] != inf)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        int ans = 0, ans_count = n;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
                if (dist[i][j] <= distanceThreshold)
                    count++;

            if (count <= ans_count)
            {
                ans_count = count;
                ans = i;
            }
        }

        return ans;
    }
};
