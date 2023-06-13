// Asteroid Collision(LeetCode)
#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> prevAsteroids;
    for (int i = 0; i < asteroids.size(); ++i)
    {
        if (asteroids[i] < 0)
        {
            // Bs isi case m collision ho skta;
            if (!prevAsteroids.empty() && prevAsteroids.top() < 0)
            {
                prevAsteroids.push(asteroids[i]);
                continue;
            }
            else if (!prevAsteroids.empty() && prevAsteroids.top() > 0)
            {

                int lastPopped = -1;
                while (!prevAsteroids.empty() && prevAsteroids.top() > 0 && prevAsteroids.top() < abs(asteroids[i]))
                {
                    lastPopped = prevAsteroids.top();
                    prevAsteroids.pop();
                }

                if (!prevAsteroids.empty() && prevAsteroids.top() == abs(asteroids[i]))
                {
                    prevAsteroids.pop();
                    continue;
                }
                else if ((lastPopped != asteroids[i]) && (prevAsteroids.empty() || prevAsteroids.top() < 0))
                {
                    prevAsteroids.push(asteroids[i]);
                    continue;
                }
            }
            else
                prevAsteroids.push(asteroids[i]);
        }
        else
            prevAsteroids.push(asteroids[i]);
    }
    vector<int> res(prevAsteroids.size());
    for (int i = (int)prevAsteroids.size() - 1; i >= 0; i--)
    {
        res[i] = prevAsteroids.top();
        prevAsteroids.pop();
    }
    return res;
}
int main()
{
    vector<int> asteroids = {-2, -2, 1, -2};
    asteroidCollision(asteroids);
}
