#include <bits/stdc++.h>
using namespace std;
// Compare Version Numbers(LeetCode)
int compareVersion(string version1, string version2)
{
    int i = 0, j = 0;
    int n1 = version1.size(), n2 = version2.size();
    int num1 = 0, num2 = 0;
    while (i < n1 || j < n2)
    {
        num1 = 0, num2 = 0;
        while (i < n1 && version1[i] != '.')
        {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }
        while (j < n2 && version2[j] != '.')
        {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }
        if(num1>num2) return 1;
        else if(num1<num2) return -1;
    }
    return 0;
}
