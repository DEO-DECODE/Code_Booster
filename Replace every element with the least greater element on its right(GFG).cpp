#include <bits/stdc++.h>
using namespace std;
// Replace every element with the least greater element on its right(GFG)
class Solution
{
public:
    vector<int> findLeastGreater(vector<int> &arr, int n)
    {
        vector<int> ans(n, -1);
        set<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            auto it = s.upper_bound(arr[i]);
            if (it != s.end())
            {
                ans[i] = (*it);
            }
            s.insert(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.findLeastGreater(arr, n);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
