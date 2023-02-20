#include <bits/stdc++.h>
using namespace std;
// Most Profit Assigning Work(LeetCode)
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
        // maximum profit
    }
    else
        return a.second < b.second;
    // minimum effort
}
int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    int n = difficulty.size();
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i)
    {
        vec.push_back({profit[i], difficulty[i]});
    }
    sort(vec.begin(), vec.end(), cmp);
    int totalProfit = 0;
    for (int i = 0; i < n; ++i)
    {
        int currDifficulty = worker[i];
        auto itr = vec.begin();
        while (itr != vec.end())
        {
            if ((*itr).second <= currDifficulty)
            {
                totalProfit += (*itr).first;
                break;
            }
            itr++;
        }
    }
    return totalProfit;
}
int main()
{
    vector<int> diffculty = {2, 5, 6, 8, 10, 15}, profit = {20, 10, 15, 40, 30, 25}, worker = {4, 8, 3, 1, 5};
    maxProfitAssignment(diffculty, profit, worker);
}
