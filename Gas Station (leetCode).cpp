#include <bits/stdc++.h>
using namespace std;
// Gas Station (leetCode)
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
   int possibleAnswer=-1, stock=0;
    if(accumulate(gas.begin(), gas.end(),0)-accumulate(cost.begin(), cost.end(),0)<0) return -1;
    for(int i=0; i<gas.size(); ++i){
        stock+=gas[i];
        stock-=cost[i];
        if(stock<0){
            stock=0;
            possibleAnswer=i+1;
        }
    }
    return possibleAnswer;
}
