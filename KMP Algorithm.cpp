#include <bits/stdc++.h>
using namespace std;
// // KMP Algorithm
// // Text : a b x a b c a b c a b  y
//           0 1 2 3 4 5 6 7 8 9 10 11
// // Pattern : a b c a b y
//      0 1 2 3 4 5
// // PrefixVec 0 0 0 1 2 0
/*
Highlighting just an instance while matching, when we find 'a' of text[3] matches with 'a' of pattern[0].
similarly 'b' of text [7] matches with 'b' of pattern[4], now 'c' doesnot matches, we will directly not start again from index 0 we will check, what is the length of the longest prefix, which is a suffix before this, we find it's of length 2 and since we are matching 'c' and 'y' , then it's clear that substring before c in the pattern matches with substring before y and therefore we will start our comparison from index 8 of text and index 2 of pattern.
*/
vector<int> prefixFunction(string s)
{
    int n = s.size();
    vector<int> pre(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = pre[j - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pre[j - 1];
        }
        if (s[i] == s[j])
            j++;
        pre[i] = j;
    }
    return pre;
}
int main()
{
    string s = "abxabcabcaby";
    string pattern = "abcaby";
    vector<int> pre = prefixFunction(s);
    int pos = -1;
    int i = 0, j = 0;
    while (i < s.size())
    {
        if (s[i] == pattern[j])
        {
            j++, i++;
        }
        else
        {
            if (j != 0)
            {
                pre[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == s.size())
        {
            pos = i - s.size();
            break;
        }
    }
    cout << "The first occurence of the pattern was found at : " << pos << endl;
}
