#include <bits/stdc++.h>
using namespace std;
// Longest Palindrome(LeetCode)

int longestPalindrome(string s)
{
    unordered_map<char, int> freqTrack;
    int charCount=0;
    for(auto ch: s){
        freqTrack[ch]++;
    }
    bool oddTaken=false;
    for(auto val: freqTrack){
        if(val.second%2==0) charCount+=val.second;
        else if(val.second%2!=0&&!oddTaken){
            oddTaken=true;
            charCount+=val.second;
        }
        else{
            charCount+=(val.second-1);
        }
    }
    return charCount;
}
