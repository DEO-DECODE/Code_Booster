#include <bits/stdc++.h>
using namespace std;
// Split Array Largest Sum(LeetCode)
int partitionsReq(vector<int> &nums, int mid)
{
    int sum=0, cnt=1;
    for(int i=0; i<nums.size(); ++i){
        if(sum+nums[i]>mid){
            sum=nums[i];
            cnt++;
        }
        else sum+=nums[i];
    }
    return cnt;
}
int splitArray(vector<int> &nums, int k)
{
    int lo = (*max_element(nums.begin(), nums.end()));
    int hi = accumulate(nums.begin(), nums.end(), 0);
    int numPartition, subarraySum = lo;
    if(k==1) return hi;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (partitionsReq(nums, mid) > k)
        {
            lo = mid + 1;
        }
        else
        {
            subarraySum = min(subarraySum, mid);
            hi = mid - 1;
        }
    }
    return subarraySum;
}
