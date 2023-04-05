#include <bits/stdc++.h>
using namespace std;
//Number of Substrings Containing All Three Characters(LeetCode)
int numberOfSubstrings(string s)
{
	int n = s.size(), i = 0, j = 0, ans = 0;
	unordered_map<char, int> freqOfchars;
	for (i = 0; i < n; ++i)
	{
		freqOfchars[s[i]]++;
		while (freqOfchars['a'] >= 1 && freqOfchars['b'] >= 1 && freqOfchars['c'] >= 1)
		{
			freqOfchars[s[j]]--;
			ans += (s.size() - i);
			j++;
		}
	}
	return ans;
}
