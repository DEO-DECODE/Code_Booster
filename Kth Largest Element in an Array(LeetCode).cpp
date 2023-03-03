//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// Kth Largest Element in an Array(LeetCode)
int findKthLargest(vector<int> &nums, int k)
{
     multiset<int> st(nums.begin(), nums.end());
    int cnt=0; 
    auto itr=st.end();
    while (cnt<k)
    {
        itr--;
        cnt++;
    }
    return (*itr);
}
