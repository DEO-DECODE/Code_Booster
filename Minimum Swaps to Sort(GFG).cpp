#include <bits/stdc++.h>
using namespace std;
// Minimum Swaps to Sort(GFG)
int minSwaps(vector<int> &nums)
{
    int n=nums.size();
    vector<pair<int, int>> numsPair;
    for(int i=0; i<n; ++i){
        numsPair.push_back({nums[i], i});
    }
    sort(numsPair.begin(), numsPair.end());
    int numSwaps=0;
    for(int i=0; i<n; ++i){
        int index=numsPair[i].second;
        if(i!=index){
            numSwaps++;
            swap(numsPair[i], numsPair[index]);
            i--;
        }
    }
    return numSwaps;
}
