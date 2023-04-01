#include <bits/stdc++.h>
using namespace std;
//The Painter's Partition Problem-II(gfg)
bool isPossible(int arr[], int n, int k, long long mid)
{
    int count = 1;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {

        if (sum + arr[i] <= mid)
        {

            sum += arr[i];
        }
        else
        {

            count++;

            if (count > k || arr[i] > mid)
            {

                return false;
            }
            else
            {

                sum = arr[i];
            }
        }
    }

    return true;
}

long long minTime(int arr[], int n, int k)
{
    long long sum = 0;

    long long lo = *max_element(arr, arr + n);

    long long hi = accumulate(arr, arr + n, sum);

    long long ans = -1;
    while (lo <= hi)
    {
        long long mid = (hi + lo) / 2;
        // cout << mid << endl;
        if (isPossible(arr, n, k, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
        // cout << lo << " " << hi << endl;
    }

    return ans;
}
