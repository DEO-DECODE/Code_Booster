#include <bits/stdc++.h>
using namespace std;
// Camelcase Matching(LeetCode)
class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        int n = queries.size(), szP = pattern.size();
        vector<bool> ans;
        for (int i = 0; i < n; ++i)
        {
            int l = 0, m = 0;
            // l-> str, m-> str
            string str = queries[i];
            int szStr = str.size();
            bool pehlehiglthogya = false;
            while (l < szStr && m < szP)
            {
                if (str[l] == pattern[m])
                {
                    l++, m++;
                }
                else if (isupper(str[l]))
                {
                    ans.push_back(false);
                    pehlehiglthogya = true;
                    break;
                }
                else
                {
                    l++;
                }
            }
            if (pehlehiglthogya)
                continue;
            ;
            if (l == szStr && m == szP)
            {
                ans.push_back(true);
                // break;
            }
            else if (l == szStr && m != szP)
            {
                ans.push_back(false);
                // break;
            }
            else
            {
                int i = l;
                for (i = l; i < szStr; ++i)
                {
                    if (isupper(str[i]))
                    {
                        ans.push_back(false);
                        break;
                    }
                }
                if (i == szStr)
                    ans.push_back(true);
            }
        }
        return ans;
    }
};
