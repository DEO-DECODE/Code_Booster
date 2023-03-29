#include <bits/stdc++.h>
using namespace std;
// Queue Reconstruction by Height(LeetCode)
static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0])
        return a[0] > b[0];
    else
        return a[1] < b[1];
}
vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> ans;
    for(auto vec: people){
        ans.insert(ans.begin()+vec[1], vec);
    }
    return ans;
}
