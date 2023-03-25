#include <bits/stdc++.h>
using namespace std;
// Minimum Number of Swaps to Make the String Balanced(LeetCode)
/*
.In the question , it is given that , we can swap chars between two indeces, any number of times and number of
'[' =n/2 and ']' is n/2 as well.
.When the number of closing brackets exceeds the already occured  opening brackets. This is where , we need to do swapping.
.When balance < 0 or balance ==-1 swap this element with first ocuuring '[' from last element.
Why are we swapping from last ?
.Suppose we don't swap the first unmatched ']' from last unmatched '[' , then we atleast need 1 more swapping to
handle the last unmatched '['.
*/
int minSwaps(string s)
{
    int balance = 0, numSwaps = 0, j = s.size() - 1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '[')
            balance++;
        else
            balance--;
        if (balance < 0)
        {
            while (j > i && s[j] != '[')
            {
                j--;
            }
            swap(s[i], s[j]);
            balance = 1;
            numSwaps++;
        }
    }
    return numSwaps;
}
