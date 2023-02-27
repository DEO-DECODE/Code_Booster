#include <bits/stdc++.h>
using namespace std;
// Bag of Tokens(LeetCode)
/*
 */
int bagOfTokensScore(vector<int> &tokens, int power)
{
    sort(tokens.begin(), tokens.end());
    int i = 0, j = tokens.size() - 1;
    int scores = 0;
    int ans=0;
    int previ=i, prevj=j;
    while (i <= j)
    {
        // cout<<i<<" "<<j<<" "<<scores<<" "<<power<<endl;
        if (tokens[i] <= power)
        {
            scores++;
            power -= tokens[i];
            i++;
        }
        else if (scores >= 1)
        {
            power += tokens[j];
            scores--;
            j--;
        }
        ans=max(ans, scores);
        if(i==previ&&j==prevj) break;
        previ=i, prevj=j;
    }
    return ans;
}
int main(){
    vector<int> tokens={400,100,200,300};
    cout<<bagOfTokensScore(tokens, 200);
}
