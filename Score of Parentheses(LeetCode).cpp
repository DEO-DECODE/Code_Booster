// Score of Parentheses(LeetCode)
#include <bits/stdc++.h>
using namespace std;
int scoreOfParentheses(string s)
{
    // It is clearly stated that parantheses are balanced.
    stack<int> st;
    // -1 indicates that parantheses is opening
    for (auto ch : s)
    {
        if (ch == '(')
        {
            st.push(-1);
        }
        else
        {
            if (st.top() != -1)
            {
                st.pop();
                st.push(1);
            }
            else
            {
                int val = 0;
                while (!st.top() == -1)
                {
                    val += st.top();
                    st.pop();
                }
                st.push(2 * val);
            }
        }
    }
    int ans=0;
    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}
