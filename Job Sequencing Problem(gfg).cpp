#include <bits/stdc++.h>
using namespace std;
// Job Sequencing Problem
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);
        int maxDeadline = -1;
        for (int i = 0; i < n; ++i)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        int prof = 0, cnt = 0;
        vector<int> schedule(maxDeadline + 1, -1);
        for (int i = 0; i < n; ++i)
        {
            // Traversing the entire jobs
            int currDeadline = arr[i].dead;
            for (int j = currDeadline; j >= 1; --j)
            {
                if (schedule[j] == -1)
                {
                    schedule[j] = arr[i].id;
                    cnt++;
                    prof += arr[i].profit;
                    break;
                }
            }
        }
        return {cnt, prof};
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends
