#include <bits/stdc++.h>
using namespace std;
// Longest Turbulent Subarray(LeetCode)
bool isCurrentIndexTurbulent(vector<int> &arr, int index)
{
    return ((arr[index] < arr[index - 1] && arr[index] < arr[index + 1]) || (arr[index] > arr[index - 1] && arr[index] > arr[index + 1]));
}
int maxTurbulenceSize(vector<int> &arr)
{
    if (arr.size() < 2)
        return arr.size();
    int start = 0, end = 0;
    int maxLength = 1;
    int n = arr.size();
    while (end + 1 < n)
    {
        if (start+1<n&&(arr[start] == arr[start + 1]))
        {
            start++;
            continue;
        }
        end = start + 1;
        while (end + 1 < n && isCurrentIndexTurbulent(arr, end))
        {
            end++;
        }
        if(end<n)
        maxLength = max(maxLength, end - start + 1);
        start = end;
    }
    return maxLength;
}
