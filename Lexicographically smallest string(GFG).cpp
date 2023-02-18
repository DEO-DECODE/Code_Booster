// Lexicographically smallest string(GFG)
#include <bits/stdc++.h>
using namespace std;
// User function Template for C++
class Solution
{
public:
    string lexicographicallySmallest(string str, int k)
    {
        int n = str.size();
        float f1 = log2(n);
        // cout << f1 << endl;
        if (f1 - (int)f1 == 0)
        {
            k = k / 2;
        }
        else
        {
            k = 2 * k;
        }
        stack<char> st;
        if (k > n)
            return "-1";
        k = n - k;

        for (int i = 0; i < n; ++i)
        {
            char curr = str[i];
            while (st.size() > 0 && curr < st.top() && ((n - i - 1) >= (k - st.size())))
            {
                st.pop();
            }
            if (st.size() < k)
            {
                st.push(curr);
            }
        }
        string finalAns = "";
        while (!st.empty())
        {
            finalAns += st.top();
            st.pop();
        }
        reverse(finalAns.begin(), finalAns.end());
        if (finalAns.size() == 0)
            return "-1";
        return finalAns;
    }
};
