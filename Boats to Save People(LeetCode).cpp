#include <bits/stdc++.h>
using namespace std;
// Boats to Save People(LeetCode)
int numRescueBoats(vector<int> &people, int limit)
{
    int n = people.size(), i;
    int numboats = 0;
    sort(people.begin(), people.end());
    for (i = 0; i < n; ++i)
    {
        if (people[i] == -1)
            continue;
        int currWt = people[i];
        auto itr = lower_bound(people.begin(), people.end(), limit - currWt);
        if (itr != people.end())
        {
            if ((*itr) > limit - currWt)
                itr--;
            people[itr - people.begin()] = -1;
        }
        people[i] = -1;
        numboats++;
    }
    return numboats;
}
int main()
{
    vector<int> people = {5, 1, 4, 2};
}
