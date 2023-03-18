// Next Greater Element III (LeetCode)
#include <bits/stdc++.h>
using namespace std;
int nextGreaterElement(int n)
{
    stack<int> st;
    while (n > 0)
    {
        st.push(n % 10);
        n = n / 10;
    }
    vector<int> digits;
    while (st.size() > 0)
    {
        digits.push_back(st.top());
        st.pop();
    }
    // digits ko array mein insert kara liya.
    int i = digits.size() - 2;
    while (i >= 0 && digits[i] >= digits[i + 1])
    {
        i--;
    }
    if (i == -1)
        return -1;
    int k = digits.size() - 1;
    while (digits[i] >= digits[k])
    {
        k--;
    }
    int temp = digits[i];
    digits[i] = digits[k];
    digits[k] = temp;
    sort(digits.begin() + i + 1, digits.end());
    long long int answ = 0;
    for (auto val : digits)
    {
        answ = answ * 10 + val;
    }
    if (answ > INT_MAX)
        return -1;
    return answ;
}
