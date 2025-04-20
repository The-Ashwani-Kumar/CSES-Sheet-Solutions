#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void SlidingCost(int N, int K, vector<ll>& arr)
{
    // Initialize two multisets to maintain smallest (lwr)
    // and largest (upr) elements
    multiset<int> lwr, upr;

    // Initialize sums of elements in lwr and upr multisets
    ll sum1 = 0, sum2 = 0;

    // Iterate through the array
    for (int i = 0; i < N; i++) {
        // Remove the (i-k)th element so that window
        // conatins k elements
        if (i >= K) {
            if (lwr.find(arr[i - K]) != lwr.end()) {
                lwr.erase(lwr.find(arr[i - K]));
                sum1 = sum1 - arr[i - K];
            }
            else {
                upr.erase(upr.find(arr[i - K]));
                sum2 = sum2 - arr[i - K];
            }
        }

        // Calculate sizes of lwr and upr multisets
        ll sz1 = lwr.size(), sz2 = upr.size();

        // Insert the current element into the appropriate
        // multiset and update the sum
        if (sz1 <= sz2) {
            lwr.insert(arr[i]);
            sum1 = sum1 + arr[i];
        }
        else {
            upr.insert(arr[i]);
            sum2 = sum2 + arr[i];
        }

        // Calculate sizes of lwr and upr multisets
        sz1 = lwr.size(), sz2 = upr.size();

        // Ensure that lwr multiset contains the smallest
        // elements and upr multiset contains the largest
        // elements
        if (sz1 > 0 && sz2 > 0) {
            // Find the maximum from lwr and the minimum
            // from upr
            auto max_lwr = lwr.rbegin();
            auto min_upr = upr.begin();

            // If the maximum element from lwr is greater
            // than the minimum element from upr, swap them.
            if (*max_lwr > *min_upr) {
                sum1 = sum1 + (*min_upr - *max_lwr);
                sum2 = sum2 + (*max_lwr - *min_upr);
                lwr.insert(*min_upr);
                upr.insert(*max_lwr);
                upr.erase(upr.find(*min_upr));
                lwr.erase(lwr.find(*max_lwr));
            }
        }

        // Output the calculated cost for the current window
        if (i >= (K - 1)) {
            ll median = *lwr.rbegin();
            cout << (sz1 * median - sum1)
                        + (sum2 - median * sz2)
                << " ";
        }
    }
}

// Driver Code
int main()
{
    int N, K;
    cin >> N >> K;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Call the SlidingCost function
    SlidingCost(N, K, arr);
}
