#include <bits/stdc++.h>
using namespace std;
// Frequency of the Most Frequent Element(LeetCode)
int maxFrequency(vector<int> &nums, int k)
{
    int cost = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    int j = 0, sm = 0;
    int ans = 1;
    for (int i = 0; i < n; ++i)
    {
        sm += nums[i];
        if ((i - j + 1) * nums[i] - sm <= k)
        {
            cout << i << " " << j << " " << sm << " " << (i - j + 1) * nums[i] - sm << endl;
            ans = max(ans, j - i + 1);
        }
        else
        {
            while ((i - j + 1) * nums[i] - sm > k)
            {
                sm -= nums[j];
                j++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 4};
    int k = 5;
    cout << maxFrequency(nums, k);
}
