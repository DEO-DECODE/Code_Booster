//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
6
-21 -67 -37 -18 4 -65
*/
// Sum of two elements with sum nearest to zero(GFG)
class Solution
{
public:
    int closestToZero(int arr[], int n)
    {
        // your code here
        sort(arr, arr + n);
        int start = 0, end = n - 1;
        int maxSum = INT_MAX, currSum = 0, ans;
        while (start < end)
        {

            currSum = arr[start] + arr[end];
            // cout << start << " " << end << " " << maxSum << " " << currSum << endl;
            if (currSum == 0)
                return 0;
            if (maxSum >= abs(0 - (arr[start] + arr[end])))
            {
                if (maxSum == abs(0 - (arr[start] + arr[end])))
                {
                    if (ans < arr[start] + arr[end])
                        ans = arr[start] + arr[end];
                }
                else
                {
                    ans = arr[start] + arr[end];
                }
                maxSum = abs(0 - (arr[start] + arr[end]));
            }
            if (abs(0 - arr[start]) > abs(0 - arr[end]))
            {
                start++;
            }
            else
            {
                end--;
            }
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}
// } Driver Code Ends
