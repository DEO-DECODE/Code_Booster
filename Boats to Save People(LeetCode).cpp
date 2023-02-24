#include <bits/stdc++.h>
using namespace std;
// Boats to Save People(LeetCode)
int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int i = 0, j = people.size() - 1, numBoats = 0;
    while (i <= j)
    {
        int sumWt = people[i] + people[j];
        if (sumWt <= limit)
        {
            i++, j--;
        }
        else
        {
            j--;
        }
        numBoats++;
    }
    return numBoats;
}
int main()
{
    vector<int> people = {5, 1, 4, 2};
}
