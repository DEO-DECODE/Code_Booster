// Count Numbers with Unique Digits(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int countNumbersWithUniqueDigits(int n)
{
    if(n==0) return 1;
    if(n==1) return 10;
    int start=9, current=9;
    int ans=10;
    while (n-->1)
    {
        current=current*(start--);
        ans+=current;
    }
    return ans;
}
