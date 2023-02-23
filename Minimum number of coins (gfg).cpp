// Minimum number of coins (gfg)
#include <bits/stdc++.h>
using namespace std;
int deno[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
class Solution
{
public:
    vector<int> minPartition(int n)
    {
        /*
        Here we can easily apply greedy Algorithm, because the sum of the previous denomination is always smaller than next denomination, therfore, greedy will never fail.
        */
        vector<int> ans;
        int i = 9;
        while (n > 0 && i >= 0)
        {
            if (deno[i] > n)
            {
                i--;
            }
            else
            {
                if (n % deno[i] == 0)
                {
                    for (int j = 0; j < n / deno[i]; ++j)
                    {
                        ans.push_back(deno[i]);
                        n = n - deno[i];
                    }
                }
                else
                {
                    ans.push_back(deno[i]);
                    n = n - deno[i];
                }
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
        int N;
        cin >> N;

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for (auto u : numbers)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
