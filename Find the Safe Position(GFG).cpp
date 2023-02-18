#include <bits/stdc++.h>
using namespace std;
// Find the Safe Position(GFG)
int winnerOfGame(int n, int k)
{
    if (n == 1)
        return 0;
    int y = winnerOfGame(n - 1, k);
    return (y + k) % n;
}
int safePos(int n, int k)
{
    return winnerOfGame(n, k) + 1;
}
