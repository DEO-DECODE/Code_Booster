#include <bits/stdc++.h>
using namespace std;
// Maximize the Confusion of an Exam(LeetCode)
int maxConsecutiveAnswers(string answerKey, int k)
{
    /*
     Here the question can be transformed to find the maximum length of substring with at most k Fs or Find the maximum length of substring with at most K Ts.
    */
    // Finding the max substring with At most K Fs
    int n = answerKey.size(), ans1 = 0, ans2 = 0, j = 0;
    unordered_map<char, int> frq1, frq2;
    for (int i = 0; i < n; ++i)
    {
        frq1[answerKey[i]]++;
        while (frq1['F'] > k)
        {
            frq1[answerKey[j]]--;
            j++;
        }
        ans1 = max(ans1, i - j + 1);
    }
    // Finding the max substring with At most K Ts
    j = 0;
    for (int i = 0; i < n; ++i)
    {
        frq2[answerKey[i]]++;
        while (frq2['T'] > k)
        {
            frq2[answerKey[j]]--;
            j++;
        }
        ans2 = max(ans2, i - j + 1);
    }
    return max(ans1, ans2);
}
