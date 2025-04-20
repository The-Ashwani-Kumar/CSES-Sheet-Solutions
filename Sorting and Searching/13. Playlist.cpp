#include<bits/stdc++.h>
#define ll long long
#define fi(a,b)  for(ll i=a;i<=b;i++)
#define fj(a,b)  for(ll j=a;j<=b;j++)
#define fk(a,b)  for(ll k=a;k<=b;k++)
#define finc(a,b,gap)   for(ll i=a;i<=b;i+=gap)
#define rf(a,b) for(ll i=a;i>=b;i--)
#define p pair<ll,ll>
#define v vector<ll>
#define vv vector<vector<ll>>
#define vp vector<pair<ll,ll>>
#define sortf(array) sort(array.begin(),array.end()
#define sortr(array) sort(array.rbegin(),array.rend())
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> songs(n);
    for(ll i = 0; i < n; i++) {
        cin >> songs[i];
    }
    
    map<ll, ll> lastPos;  // Using map instead of unordered_map for better performance
    ll start = 0, maxLen = 0;
    
    for(ll i = 0; i < n; i++) {
        if(lastPos.count(songs[i]) && lastPos[songs[i]] >= start) {
            start = lastPos[songs[i]] + 1;
        }
        lastPos[songs[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }
    
    cout << maxLen;
    return 0;
}