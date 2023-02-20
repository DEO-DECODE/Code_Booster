#include <bits/stdc++.h>
using namespace std;
// Push Dominoes(LeetCode)
string pushDominoes(string dominoes)
{
    int n = dominoes.size();
    vector<int> left(n), right(n);
    int nearestIndex = -1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (dominoes[i] == 'L')
        {
            nearestIndex = i;
        }
        else if (dominoes[i] == 'R')
        {
            nearestIndex = -1;
        }
        left[i] = nearestIndex;
    }
    nearestIndex = -1;
    for (int i = 0; i < n; ++i)
    {
        if (dominoes[i] == 'R')
        {
            nearestIndex = i;
        }
        else if (dominoes[i] == 'L')
        {
            nearestIndex = -1;
        }
        right[i] = nearestIndex;
    }
    // for (int i = 0; i < n; ++i)
    //     cout << left[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; ++i)
    //     cout << right[i] << " ";
    // cout << endl;
    string ans;
    for (int i = 0; i < n; ++i)
    {
        int nearestLeft, nearestRight;
        if (left[i] == -1)
            nearestLeft = 1e5;
        else
        {
            nearestLeft = abs(i - left[i]);
        }
        if (right[i] == -1)
            nearestRight = 1e5;
        else
        {
            nearestRight = abs(i - right[i]);
        }
        if (nearestLeft < nearestRight)
        {
            ans += "L";
        }
        else if (nearestLeft > nearestRight)
        {
            ans += "R";
        }
        else
        {
            ans += ".";
        }
    }
    return ans;
}
int main()
{
    string str = ".L.R...LR..L..";
    pushDominoes(str);
}
