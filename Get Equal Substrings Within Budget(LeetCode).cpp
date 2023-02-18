#include <bits/stdc++.h>
using namespace std;
// Get Equal Substrings Within Budget(LeetCode)
int equalSubstring(string s, string t, int maxCost)
{
    int n = s.size();
    int cost = 0, ans = 0, j = 0;
    for (int i = 0; i < n; ++i)
    {
        cost += abs(s[i] - t[i]);
        while (j < n && (cost > maxCost))
        {
            cost -= (abs(s[j] - t[j]));
            j++;
        }
        // while loop ek baar extra chal hi rha.
        ans = max(ans, i - j + 1);
    }
    return ans;
}
