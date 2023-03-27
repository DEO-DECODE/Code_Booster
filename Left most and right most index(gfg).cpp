#include <bits/stdc++.h>
using namespace std;
// Left most and right most index
pair<long, long> indexes(vector<long long> v, long long x)
{
    pair<long, long> ans = {-1, -1};
    int n = v.size();
    int lo = 0, hi = n - 1, focc=-1, locc=-1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid] == x)
        {
            ans = {mid, mid};
            focc=mid, locc=mid;
            break;
        }
        if (v[mid] > x)
            hi = mid - 1;
        else if (v[mid] < x)
            lo = mid + 1;
    }
    while (focc - 1 >= 0 && v[focc - 1] == v[focc])
    {
        focc--;
    }
    while (locc + 1 < n && v[locc] == v[locc + 1])
    {
        locc++;
    }
    ans = {focc, locc};
    return ans;
}
