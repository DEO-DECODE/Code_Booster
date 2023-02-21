#include <bits/stdc++.h>
using namespace std;
// Repeated String Match(LeetCode)

bool isValid(unordered_map<char, int> freqOfb, unordered_map<char, int> freqOfTemp)
{
    int cnt = 0;
    for (auto val : freqOfb)
    {
        if (freqOfTemp[val.first] > 2 * freqOfb[val.first])
        {
            cnt++;
        }
    }
    if (cnt >= freqOfb.size())
        return false;
    return true;
}
int repeatedStringMatch(string a, string b)
{
    // string a ko b mein convert krna hai
    string temp = "";
    if (temp == b)
        return 0;
    int cnt = 0;
    for (int i = 0; i < b.size(); ++i)
    {
        int index = a.find(b[i]);
        if (index >= a.size())
            return -1;
    }
    unordered_map<char, int> freqOfTemp, freqOfb;
    for (auto ch : b)
    {
        freqOfb[ch]++;
    }
    while (isValid(freqOfb, freqOfTemp))
    {
        temp += a;
        cnt++;
        for (auto ch : a)
        {
            freqOfTemp[ch]++;
        }
        int index = temp.find(b);
        if (index < temp.length())
        {
            return cnt;
        }
    }
    return -1;
}
