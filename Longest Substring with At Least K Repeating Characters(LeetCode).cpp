#include <bits/stdc++.h>
using namespace std;
//Longest Substring with At Least K Repeating Characters(LeetCode)
int helper(int start, int end, string &s, int k)
{
    if (end - start < k)
        return 0;
    unordered_map<char, int> track;
    for (int i = start; i < end; ++i)
    {
        track[s[i]]++;
    }
    // end is exclusive, whereas start is inclusive
    for (int i = start; i < end; ++i)
    {
        if (track[s[i]] < k)
        {
            int firstPart = helper(start, i, s, k);
            int j = i + 1;
            while (j < end && track[s[j]] < k)
            {
                j++;
            }
            int secondPart = helper(j, end, s, k);
            return max(firstPart, secondPart);
        }
    }
    return end - start;
}
int longestSubstring(string s, int k)
{
    return helper(0, s.size(), s, k);
}
