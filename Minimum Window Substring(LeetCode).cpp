#include <bits/stdc++.h>
using namespace std;
// Minimum Window Substring(LeetCode)
string minWindow(string s, string t)
{
    string ans;
    int minLength = INT_MAX;
    if (s.size() == 0 || t.size() == 0)
        return "";
    unordered_map<char, int> window, original;
    for (auto ch : t)
    {
        original[ch]++;
    }
    int i = 0, j = 0, letterCount = 0;
    for (i = 0; i < s.size(); ++i)
    {
        if ( original.find(s[i]) != original.end())
        {
            window[s[i]]++;
            if (window[s[i]] <= original[s[i]])
                letterCount++;
        }
        if (letterCount >= t.size())
        {
            while (original.find(s[j]) == original.end() || (window[s[j]] > original[s[j]]))
            {
                window[s[j]]--;
                j++;
            }
            if (i - j + 1 < minLength)
            {
                minLength = i - j + 1;
                ans = s.substr(j, minLength);
            }
        }
    }
    return ans;
}
int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl;
}
