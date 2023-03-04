#include <bits/stdc++.h>
using namespace std;
// Top K Frequent Elements(LeetCode)
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    for (auto val : nums)
    {
        freq[val]++;
    }
    map<int, vector<int>> mp;
    for (auto pr : freq)
    {
        mp[pr.second].push_back(pr.first);
    }
    vector<int> finalAns;
    auto itr=--mp.end();
    while (k)
    {
        for(auto val: (*itr).second){
            finalAns.push_back(val);
            k--;
            if(k==0) break;
        }
        if(itr==mp.begin()) break;
        itr--;
    }
    return finalAns;
}
