#include <bits/stdc++.h>
using namespace std;
// Maximum Subarray Min-Product(LeetCode)
int maxSumMinProduct(vector<int> &nums)
{
    /*
    We have to find the maximum min product , which is equal to the array's sum multiplied by the least element in the array.
    */
    int n = nums.size();
    vector<long> preFixSum(n), left(n, -1), right(n, n);
    preFixSum.push_back(0);
    preFixSum[0] = nums[0];
    // Getting perfix sum of given array to reduce complexity by avoiding recalculation
    for (int i = 1; i < nums.size(); i++)
        preFixSum[i] = preFixSum[i - 1] + nums[i];
    stack<int> st1, st2;
    for (int i = 0; i < n; i++)
    {
        while (!st1.empty() && nums[i] < nums[st1.top()])
        {
            right[st1.top()] = i;
            st1.pop();
        }
        st1.push(i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st2.empty() && nums[i] < nums[st2.top()])
        {
            left[st2.top()] = i;
            st2.pop();
        }

        st2.push(i);
    }
    for (auto val : nums)
    {
        cout << val << " ";
    }
    cout << endl;
    for (auto val : right)
    {
        cout << val << " ";
    }
    cout << endl;
    for (auto val : left)
    {
        cout << val << " ";
    }
    cout << endl;
    long long ans = 0, mod = 1e9 + 7;

    // finally calculating the contribution of each element
    for (int i = 0; i < nums.size(); i++)
    {
        int lm = left[i];
        int rm = right[i];
        long long temp = 1ll * nums[i] * (1ll) * (preFixSum[rm - 1] - preFixSum[lm + 1] + nums[lm + 1]);
        ans = max(ans, temp);
    }

    return ans % mod;
}
int main()
{
    vector<int> nums = {2, 3, 1, 4, 7, 4, 5};
    cout << maxSumMinProduct(nums);
}
