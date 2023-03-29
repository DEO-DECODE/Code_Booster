#include <bits/stdc++.h>
using namespace std;
// Contains Duplicate III(LeetCode)

bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
{
    set<long long> elements;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto itr1 = elements.lower_bound(nums[i] - valueDiff);
        auto itr2 = elements.lower_bound(nums[i] + valueDiff);
        if (itr1 != elements.end())
            if (abs((*itr1) - nums[i]) <= valueDiff)
                return true;
        if (itr2 != elements.end())
            if (abs((*itr2) - nums[i]) <= valueDiff)
                return true;
        // Acquire
        elements.insert(nums[i]);
        // Release
        if (i >= indexDiff)
            elements.erase(nums[i - indexDiff]);
    }
    return false;
}
