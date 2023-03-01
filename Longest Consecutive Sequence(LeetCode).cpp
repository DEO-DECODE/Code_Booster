#include <bits/stdc++.h>
using namespace std;
// Longest Consecutive Sequence(LeetCode)
int longestConsecutive(vector<int> &nums)
{
    int ans=1;
    unordered_set<int> st(nums.begin(), nums.end());
    for(auto val: nums){
        if(st.find(val-1)==st.end()){
            int currentNumber= val;
            int maxm=1;
            while (st.find(currentNumber+1)!=st.end())
            {
                currentNumber++, maxm++;
            }
            ans=max(ans, maxm);
        }
    }
    return ans;
}
