#include <bits/stdc++.h>
using namespace std;
// Gas Station (leetCode)
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    if(accumulate(gas.begin(), gas.end(),0)-accumulate(cost.begin(), cost.end(),0)<0) return -1;
    int n=gas.size();
    queue<int> q;
    q.push(0);
    int netPetrol = 0;
    while (q.size() < n)
    {
        int pp = q.back();
        netPetrol += (gas[pp] - cost[pp]);
        if (netPetrol < 0)
        {
            while (q.size() > 0)
            {
                q.pop();
            }
        }
        if (q.empty())
            netPetrol = 0;
        q.push((pp + 1) % n);
    }
    return q.front();
}
