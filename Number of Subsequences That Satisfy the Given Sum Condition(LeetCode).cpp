#include <bits/stdc++.h>
using namespace std;
// Number of Subsequences That Satisfy the Given Sum Condition(LeetCode)
const int m = 1e9 + 7;
int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b = b >> 1;
    }
    return ans;
}
int numSubseq(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n=nums.size();
    int i=0, j=n-1, ans=0;
    while (i<=j)
    {
        if(nums[i]+nums[j]<=target){
            ans=(ans+binExp(2,j-i))%m;
            i++;
        }
        else{
            j--;
        }
    }
    return ans;
    
}
