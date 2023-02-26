#include <bits/stdc++.h>
using namespace std;
// String Compression(LeetCode)
int compress(vector<char> &chars)
{
    int i = 0, j = 0;
    int n = chars.size();
    while (i < n)
    {
        chars[j] = chars[i];
        int cnt = 0;
        while (i < n && chars[j] == chars[i])
        {
            i++, cnt++;
        }
        if (cnt == 1)
        {
            j++;
        }
        else{
            string freq=to_string(cnt);
            for(auto ch: freq){
                chars[++j]=ch;
            }
            j++;
        }
    }
    return j;
}
