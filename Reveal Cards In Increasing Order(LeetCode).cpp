// Reveal Cards In Increasing Order(LeetCode)
#include <bits/stdc++.h>
using namespace std;
vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    int n = deck.size();
    queue<int> q;
    for (int i = 0; i < n; ++i)
        q.push(i);
    sort(deck.begin(), deck.end());
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
    {
        res[q.front()] = deck[i];
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return res;
}
