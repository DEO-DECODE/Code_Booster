#include <bits/stdc++.h>
using namespace std;
// Save Your Life(GFG)
string maxSum(string w, char x[], int b[], int n)
{
    unordered_map<char, int> hashMap;
    for (int i = 0; i < n; ++i)
    {
        hashMap[x[i]] = b[i];
    }
    string ans = "";
    int currSum = 0, j = 0, maxSum = INT_MIN;
    for (int i = 0; i < w.size(); ++i)
    {
        int ascii;
        if (hashMap.find(w[i]) != hashMap.end())
        {
            ascii = hashMap[w[i]];
        }
        else
        {
            ascii = (int)w[i];
        }
        currSum += ascii;

        if (maxSum < currSum)
        {
            maxSum = currSum;
            ans = w.substr(j, i - j + 1);
        }
        if (currSum < 0)
        {
            j = i + 1;
            currSum = 0;
        }
    }
    return ans;
}
