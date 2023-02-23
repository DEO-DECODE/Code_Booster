#include <bits/stdc++.h>
using namespace std;
// Shortest Palindrome(LeetCode)
string shortestPalindrome(string s)
{
    string temp = s;
    string str = s;
    reverse(s.begin(), s.end());
    if (temp == s)
        return temp;
    str.push_back('#');
    str += s;
    int n = str.size();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = lps[i - 1];
        while (j > 0 && str[i] != str[j])
        {
            j = lps[j - 1];
        }
        if (str[i] == str[j])
        {
            j++;
        }
        lps[i] = j;
        cout << i << " " << lps[i] << endl;
    }
    int valueOfLongestPrefixWhichIsASuffix = lps[n - 1];
    cout << "valueOfLongestPrefixWhichIsASuffix : " << valueOfLongestPrefixWhichIsASuffix << endl;
    string temp2 = temp.substr(valueOfLongestPrefixWhichIsASuffix);
    cout << "temp2 : " << temp2 << endl;
    reverse(temp2.begin(), temp2.end());
    return temp2 + temp;
}
int main()
{
    string s = "aabba";
    cout << shortestPalindrome(s);
}
