#include <bits/stdc++.h>
using namespace std;
// Count Collisions on a Road(leetCode)
int countCollisions(string str)
{
    int n = str.size();
    stack<char> st;
    int coll = 0;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == 'L')
        {
            if ((!st.empty()) && st.top() == 'R')
            {
                coll += 2;
                st.pop();
                st.push('S');
            }
            else if ((!st.empty()) && st.top() == 'S')
            {
                coll += 1;
            }
            else
            {
                st.push('L');
            }
        }
        else if (str[i] == 'R')
        {
            st.push('R');
        }
        else if (str[i] == 'S')
        {
            if ((!st.empty()) && st.top() == 'R')
            {
                coll += 1;
                st.pop();
                st.push('S');
            }
            else
            {
                st.push('S');
            }
        }
    }
    int cnt = 0;
    while (!st.empty())
    {
        char dir = st.top();
        st.pop();
        if (dir == 'R')
            coll += cnt;
        else if (dir == 'S')
            cnt = 1;
    }
    return coll;
}
