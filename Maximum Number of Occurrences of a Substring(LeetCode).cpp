#include <bits/stdc++.h>
using namespace std;
// Maximum Number of Occurrences of a Substring(LeetCode)
int maxFreq(string s, int k, int minSize, int maxSize)
{
	unordered_map<char, int> frequencyOfCharacters;
	unordered_map<string, int> frequencyOfSubs;
	int j = 0, maxOccurence = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		frequencyOfCharacters[s[i]]++;
		// inValid window
		while (i - j + 1 > maxSize || frequencyOfCharacters.size() > k)
		{
			frequencyOfCharacters[s[j]]--;
			if (frequencyOfCharacters[s[j]] == 0)
			{
				frequencyOfCharacters.erase(frequencyOfCharacters.find(s[j]));
			}
			j++;
		}
		// Valid window
		while (i - j + 1 >= minSize && i - j + 1 <= maxSize && frequencyOfCharacters.size() <= k)
		{
			maxOccurence = max(maxOccurence, ++frequencyOfSubs[s.substr(j, i - j + 1)]);
			if (--frequencyOfCharacters[s[j]] == 0)
			{
				frequencyOfCharacters.erase(frequencyOfCharacters.find(s[j]));
			}
			j++;
		}
	}
	return maxOccurence;
}
