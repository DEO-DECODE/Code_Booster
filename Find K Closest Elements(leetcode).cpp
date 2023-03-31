#include <bits/stdc++.h>
using namespace std;
// Find K Closest Elements(leetcode)
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int lo = 0, hi = arr.size() - 1;
    while (hi - lo >= k)
    {
        if (abs(x - arr[lo]) > abs(x - arr[hi]))
            lo++;
        else
            hi--;
    }
    vector<int> ans;
    for (int i = lo; i <= hi; ++i)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    auto ans = findClosestElements(arr, 4, 3);
}
