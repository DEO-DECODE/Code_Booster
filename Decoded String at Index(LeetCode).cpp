#include <bits/stdc++.h>
using namespace std;
// Decoded String at Index(LeetCode)
/*

*/
string decodeAtIndex(string s, int k)
{
    int sz = 0;
    // Calculating length of the expanded string.
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            sz = sz * (s[i] - '0');
        }
        else
            sz--;
    }
    string ans;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        k = k % sz;
        if ((k == 0 || k == sz) && isalpha(s[i]))
        {
            ans.push_back(s[i]);
            return ans;
        }

        
        if (isdigit(s[i]))
        {
            sz = sz / (s[i] - '0');
        }
        else
            sz--;
    }
    return ans;
}
