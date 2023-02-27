#include <bits/stdc++.h>
using namespace std;
// Expressive Words(LeetCode)
/*
s = "heeellooo", words = ["hello", "hi", "helo"]
*/
bool canBeStretchy(string s, string t)
{
    int n1 = s.size(), n2 = t.size();
    int i = 0, j = 0;
    while (i < n1 || j < n2)
    {
        int cnts = 1;
        while ((i + 1 < n1) && (s[i] == s[i + 1]))
        {
            i++, cnts++;
        }
        int cntt = 1;
        while ((j + 1 < n2) && (t[j] == t[j + 1]))
        {
            j++, cntt++;
        }
        if (s[i] != t[j])
            return false;
        if (cnts != cntt)
        {
            if (cnts < cntt)
                return false;
            else if (cnts < 3)
                return false;
        }
        i++;
        j++;
    }
    return true;
}
int expressiveWords(string s, vector<string> &words)
{
    int n=words.size();
    int ans=0;
    for(int i=0; i<n; ++i){
        if(canBeStretchy(s,words[i])){
            ans++;
        }
    }
    return ans;
}
