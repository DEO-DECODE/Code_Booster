#include <bits/stdc++.h>
using namespace std;
// Chef and Riffles Problem Code: RIFFLES
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> next(n + 1);
    for (int i = 1; i <= n / 2; ++i)
    {
        // if(i%2){
        next[i] = 2 * i - 1;
        // }
    }
    int temp = 2;
    for (int i = n / 2 + 1; i <= n; ++i)
    {
        // if(i%2){
        next[i] = temp;
        temp += 2;
        // }
    }
    for (int i = 1; i <= n; ++i)
        cout << next[i] << " ";
    cout << "\n\n";
    vector<int> vis(n + 1);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        int num = i;
        vector<int> cycle;
        cycle.push_back(num);
        vis[num] = 1;
        while (next[num] != i)
        {
            num = next[num];
            cycle.push_back(num);
            vis[num] = 1;
        }
        for (int i = 0; i < cycle.size(); ++i)
        {
            cout << cycle[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < cycle.size(); ++i)
        {
            ans[cycle[i]] = cycle[(i + k) % cycle.size()];
        }
    }
    cout << "\n\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
}
