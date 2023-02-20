#include <bits/stdc++.h>
using namespace std;
//  Advantage Shuffle(LeetCode)
/*
Input:
nums1 = [12,24,8,32],
nums2 = [13,25,32,11]
Output: [24,32,8,12]
*/
vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
{
    /*
    The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
    */
    multiset<int> temp;
    for (auto val : nums1)
    {
        temp.insert(val);
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); ++i)
    {
        auto itr = temp.upper_bound(nums2[i]);
        if (itr == temp.end())
        {
            ans.push_back((*temp.begin()));
            temp.erase(temp.begin());
        }
        else
        {
            ans.push_back(*itr);
            temp.erase(itr);
        }
    }
    return ans;
}
