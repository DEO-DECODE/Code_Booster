#include <bits/stdc++.h>
using namespace std;
// Replace Elements with Greatest Element on Right Side(LeetCode)
vector<int> replaceElements(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    set<int> s;
    int greatestInRight=INT_MIN;
    greatestInRight=max(greatestInRight, arr[n-1]);
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i]=greatestInRight;
        greatestInRight=max(greatestInRight, arr[i]);
    }
    return ans;
}
