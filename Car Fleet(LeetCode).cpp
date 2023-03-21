#include <bits/stdc++.h>
using namespace std;
// Car Fleet(LeetCode)
/*
We are simply calculating time taken by each car to arrive at deatination and then we are traversing frome end. If time taken by
any car is more than the last traversed then it will combine to the last fleet and so on.
 */
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    map<int, double> carTrack;
    int n = position.size();
    for (int i = 0; i < n; ++i)
    {
        carTrack[position[i]] = (double)(target - position[i]) / speed[i];
    }
    // SlowestCar will take the maximum time to reach the target.
    auto itr = --carTrack.end();
    int fleets = 1;
    double slowestCar = (*itr).second;
    while (true)
    {
        auto timeTaken = (*itr).second;
        if (timeTaken > slowestCar)
        {
            fleets++;
            slowestCar = timeTaken;
        }
        if (itr == carTrack.begin())
            break;
        itr--;
    }
    return fleets;
}
