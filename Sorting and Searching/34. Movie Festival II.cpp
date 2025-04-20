#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Sorting function to sort movies based on start times
bool sortcol2(const vector<ll> &v1, const vector<ll> &v2)
{
    return v1[0] < v2[0];
}

// Function to optimize movie-watching schedule
void MovieFestivalII(int n, int k, vector<vector<ll>> &a)
{
    // Multiset to store end times of assigned movies
    multiset<int> st;

    // Variable to keep track of entirely watchable movies
    ll ans = 0;

    // Initialize multiset with end times of first k movies
    for (int i = 0; i < k; i++)
    {
        st.insert(a[i][1]);
    }

    // Iterate over the remaining movies
    for (int i = k; i < n; i++)
    {
        // Iterator pointing to minimum end time
        auto mn = st.begin();
        // Iterator pointing to maximum end time
        auto mx = st.rbegin(); 

        // If the start time of the current movie is after or equal to the minimum end time,
        // it can be entirely watched, so increment the count and update the multiset
        if (a[i][0] >= (*mn))
        {
            ans++;
            st.erase(mn);
            st.insert(a[i][1]);
        }
        // If the end time of the current movie is less than the maximum end time,
        // replace the movie with the maximum end time in the multiset
        else if (a[i][1] < (*mx))
        {
            st.erase(st.find(*mx));
            st.insert(a[i][1]);
        }
    }

    // Print the total number of entirely watchable movies
    cout << ans + st.size() << "\n";
}

// Driver Code
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }

    // Sort movies based on start times
    sort(a.begin(), a.end(), sortcol2);

    // Call the function to optimize movie-watching schedule
    MovieFestivalII(n, k, a);
}
