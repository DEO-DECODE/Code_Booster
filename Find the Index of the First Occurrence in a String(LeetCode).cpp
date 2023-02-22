#include <bits/stdc++.h>
using namespace std;
// Find the Index of the First Occurrence in a String(LeetCode)
int strStr(string haystack, string needle)
{
    if (needle.length() == 0)
        return 0;
    int ind = haystack.find(needle);
    if (ind > haystack.length())
        return -1;
    return ind;
}
