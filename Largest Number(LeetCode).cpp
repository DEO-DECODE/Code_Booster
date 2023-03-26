#include <bits/stdc++.h>
using namespace std;
// Largest Number(LeetCode)
static bool cmp(string &a, string &b)
{
    return a + b > b + a;
}
string largestNumber(vector<int> &nums)
{
    vector<string> numbers;
    for (auto num : nums)
    {
        numbers.push_back(to_string(num));
    }
    string ans = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for (auto str : numbers)
    {
        ans += str;
    }
    int index = 0;
    while (index < ans.size() - 1 && ans[index] == '0')
    {
        ++index;
    }
    return ans.substr(index);
}
