#include <bits/stdc++.h>
using namespace std;
// Partition Labels(LeetCode)
vector<int> partitionLabels(string s)
{
    map<char, pair<int, int>> mp;
    vector<int> ans;
    for (int i = 0; i < s.size(); ++i)
    {
        if (mp.find(s[i]) == mp.end())
        {
            mp[s[i]] = {i, i};
        }
        else
        {
            auto &pr = mp[s[i]];
            pr.second = i;
        }
    }
    set<pair<int, int>> st;
    for (auto val : mp)
    {
        // cout << val.first << " " << val.second.first << " " << val.second.second << endl;
        st.insert({val.second.first, val.second.second});
    }
    int cnt = 0;
    auto itr = st.begin();
    int start = (*itr).first, ending = (*itr).second;
    itr++;
    while (itr != st.end())
    {
        if ((*itr).first <= ending)
        {
            ending = max(ending, (*itr).second);
        }
        else
        {
            ans.push_back(ending - start + 1);
            start = (*itr).first, ending = (*itr).second;
        }
        itr++;
    }

    return ans;
}
int main()
{
    string s = "ababcbacadefegdehijhklij";
    partitionLabels(s);
}
