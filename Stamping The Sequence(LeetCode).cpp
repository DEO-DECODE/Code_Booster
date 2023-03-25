#include <bits/stdc++.h>
using namespace std;
//Stamping The Sequence(LeetCode)
bool canReplace(string &target, string &stamp, int pos)
{
    for (int i = 0; i < stamp.size(); ++i)
    {
        if (target[i + pos] != '*' && target[i + pos] != stamp[i])
            return false;
    }
    return true;
}
int numReplace(string &target, string &stamp, int pos)
{
    int cnt = 0;
    for (int i = 0; i < stamp.size(); ++i)
    {
        if (target[i + pos] != '*')
        {
            target[i + pos] = '*';
            cnt++;
        }
    }
    return cnt;
}
vector<int> movesToStamp(string stamp, string target)
{
    int cnt = 0, i;
    vector<int> ans, vis(target.size() + 1);

    while (cnt < target.size())
    {
        bool noChange = true;
        for (i = 0; i < target.size(); ++i)
        {
            if (!vis[i] && canReplace(target, stamp, i))
            {
                vis[i] = 1;
                noChange = false;
                cnt += numReplace(target, stamp, i);
                ans.push_back(i);
                if (cnt == target.size())
                    break;
            }
        }
        if (noChange)
            return {};
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
