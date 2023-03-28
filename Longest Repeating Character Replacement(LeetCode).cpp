#include <bits/stdc++.h>
using namespace std;
// Longest Repeating Character Replacement(LeetCode)
int characterReplacement(string s, int k)
{
    unordered_map<char, int> currentWindow;
    int j = 0, freqOfMostFrequentLetter = 0, ans=0;
    for (int i = 0; i < s.size(); ++i)
    {
        currentWindow[s[i]]++;
        freqOfMostFrequentLetter = max(freqOfMostFrequentLetter, currentWindow[s[i]]);
        int lettersToChange = (i - j + 1) - freqOfMostFrequentLetter;
        if(lettersToChange > k)
        {
            currentWindow[s[j]]--;
            j++;
        }
        ans=max(ans, i-j+1);
    }
    return ans;
}
