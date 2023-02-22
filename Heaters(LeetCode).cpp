#include <bits/stdc++.h>
using namespace std;
// Heaters(LeetCode)
class Solution
{
public:
    bool isPossible(vector<int> &houses, vector<int> &heaters, int radius)
    {
        int n = houses.size(), m = heaters.size(), i = 0, j = 0;
        while (i < n)
        {
            if (j == m)
            {
                return false;
                // We have used all the heaters but, we are unable to cover all the houses.
            }
            if (houses[i] <= heaters[j] + radius && houses[i] >= heaters[j] - radius)
            {
                i++;
                // Current heater can cover the current house, so we will simply check for the next house.
            }
            else
            {
                j++;
                // we will check for next heater.
            }
        }
        return true;
    }
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int lo = 0, hi = 1e9, ans = 1e9;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (isPossible(houses, heaters, mid))
            {
                ans = min(ans, mid);
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
