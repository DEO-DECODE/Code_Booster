#include <bits/stdc++.h>
using namespace std;
// Longest Happy Prefix(LeetCode)
string longestPrefix(string s)
{
    int n = s.size();
    vector<int> pre(n, 0);
    int i = 1, j = 0;
    for (i = 1; i < n; ++i)
    {
        j = pre[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pre[j - 1];
        }
        if (s[i] == s[j])
            j++;
        pre[i] = j;
    }
    string str = "";
    int val = 0;
    val = pre[n - 1];
    if (val != 0)
        str = s.substr(0, pre[n - 1]);
    return str;
}
