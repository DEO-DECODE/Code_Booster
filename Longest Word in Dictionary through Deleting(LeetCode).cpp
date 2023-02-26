#include <bits/stdc++.h>
using namespace std;
// Longest Word in Dictionary through Deleting(LeetCode)
bool longestWord(string s, string t)
{
    int i = 0, j = 0;
    // i -> s, j -> t
    // t dictionary wala hai.
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            i++, j++;
        }
        else
        {
            i++;
        }
    }
    return j == t.size();
}
string findLongestWord(string s, vector<string> &dictionary)
{
    string ans = "";
    for (int i = 0; i < dictionary.size(); ++i)
    {
        if (longestWord(s, dictionary[i]))
        {
            if (dictionary[i].size() > ans.size() || (dictionary[i].size() == ans.size() && dictionary[i] < ans))
            {
                ans = dictionary[i];
            }
        }
    }
    return ans;
}
int main()
{
    vector<string> dictionary = {"ale", "apple", "monkey", "plea"};
    string s = "abpcplea";
    cout << findLongestWord(s, dictionary);
}
