#include <bits/stdc++.h>
using namespace std;
// Candy(LeetCode)
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> leftNeighbors(n, 1), rightNeighbors(n, 1);
    for (int i = 1; i < n; ++i)
    {
        if (ratings[i] > ratings[i - 1])
        {
            leftNeighbors[i] = leftNeighbors[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; --i)
    {
        if (ratings[i] > ratings[i + 1])
        {
            rightNeighbors[i] = rightNeighbors[i + 1] + 1;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        leftNeighbors[i] = max(leftNeighbors[i], rightNeighbors[i]);
    }
    return accumulate(leftNeighbors.begin(), leftNeighbors.end(), 0);
}
