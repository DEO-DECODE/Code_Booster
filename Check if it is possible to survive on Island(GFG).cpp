#include <bits/stdc++.h>
using namespace std;
// Check if it is possible to survive on Island(GFG)
class Solution{
public:
    int minimumDays(int S, int N, int M){
        int FoodReq=S*M;
        int numSunday=S/7;
        S=S-numSunday;
        int minimumBuyDays=FoodReq/N;
        if(FoodReq%N!=0) minimumBuyDays++;
        if(minimumBuyDays<=S) return minimumBuyDays;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends
