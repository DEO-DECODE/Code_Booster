#include <bits/stdc++.h>
using namespace std;
//Split Array into Consecutive Subsequences(leetCode)
bool isPossible(vector<int> &nums)
{
    unordered_map<int , int> freq, need;
    for(auto num: nums){
        freq[num]++;
    }
    for(auto val: nums){
        if(freq[val]==0) continue;
        // Possiblity 1
        if(need[val]>0){
            need[val]--;
            freq[val]--;
            need[val+1]++;
        }
        else if(freq[val]>0&&freq[val+1]>0&&freq[val+2]>0){
            freq[val]--;
            freq[val+1]--;
            freq[val+2]--;
            need[val+3]++;
        }
        else return false;
    }
    return true;
}
