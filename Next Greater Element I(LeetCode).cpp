// Next Greater Element I(LeetCode)
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> track;
    int n1 = nums1.size(), n2 = nums2.size();
    stack<int> st;
    vector<int> nge(n2, -1);
    for (int i = 0; i < nums2.size(); ++i)
    {
        track[nums2[i]] = i;
        while (!st.empty() && nums2[st.top()] < nums2[i])
        {
            nge[st.top()] = nums2[i];
            st.pop();
        }
        st.push(i);
    }
    vector<int> ans;
    for (auto val : nums1)
    {
        ans.push_back(nge[track[val]]);
    }
    return ans;
}
