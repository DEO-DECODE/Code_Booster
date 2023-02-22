#include <bits/stdc++.h>
using namespace std;
// Minimum characters to be added at front to make string palindrome(GFG)
/*
Any General case: string
                part1: Palindrome part2: notPalindrome
                ex: babccd
                here bab is a palindrome and ccd is not a palindrome
                ex2 : abcdef
                here a is a plaindrome and bcdef is not a palindrome.
Intuition:
Idea is to find the longest common prefix, because, if we have palindrome prefix, then we just need to put the rest of the letters in the reverse order in front of the string . In example 1 we just need to put ccd in front.
and the string will be ccdbabccd.
If we concate the strin with it's reverse then the value stored at the index n-1 is equal to the longest prefix which is a suffix.
*/

int minChar(string str)
{
    string s = str;
    reverse(s.begin(), s.end());
    str += s;
    int n = str.size();
    vector<int> lps(n, 0);
    int i = 1, j = 0;
    for (int i = 1; i < n; ++i)
    {
        j = lps[i - 1];
        while (j > 0 && str[i] != str[j])
        {
            j = lps[j - 1];
        }
        if (str[i] == str[j])
        {
            j++;
        }
        lps[i] = j;
    }
    return n / 2 - lps[n - 1];
}
