#include <bits/stdc++.h>
using namespace std;
// Find All Anagrams in a String(LeetCode)
bool check(unordered_map<char, int> originalFreq, unordered_map<char, int> currentFreq)
{
    for (auto val : currentFreq)
    {
        if (originalFreq[val.first] != val.second)
            return false;
    }
    return true;
}
vector<int> findAnagrams(string s, string p)
{
    unordered_map<char, int> originalFreq, currentFreq;
    for (auto ch : p)
    {
        originalFreq[ch]++;
    }
    /*
    hum yaha pr fixed sliding window length le rhein hain. because jo permutations hai p ke wo to same hi honge naa.
    */
    vector<int> ans;
    for (int i = 0; i < p.length(); ++i)
    {
        currentFreq[s[i]]++;
    }
    int j = p.length();
    while (j < s.size())
    {
        if (check(originalFreq, currentFreq))
        {
            ans.push_back(j - p.size());
        }
        // Fixed Size Sliding window pattern
        // Acquire
        currentFreq[s[j]]++;
        // Release
        currentFreq[s[j - p.size()]]--;
        j++;
    }
    if (check(originalFreq, currentFreq))
    {
        ans.push_back(j - p.size());
    }
    return ans;
}
