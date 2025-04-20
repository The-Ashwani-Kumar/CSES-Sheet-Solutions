#include<bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define rf(i,a,b) for(ll i=a;i>=b;i--)
#define fg(i,a,b,gap) for(ll i=a;i<=b;i+=gap)
#define v(dataType) vector<dataType>
#define vv(dataType) vector<vector<dataType>>
#define vp(dataType1,dataType2) vector<pair<dataType1,dataType2>>
#define sortV(s) sort(s.begin(),s.end())
#define sortR(s) sort(s.rbegin(),s.rend())
using namespace std;

int main(){
    
    ll x,n;
    cin >> x >> n;
    vector<ll> trafficLights(n);
    f(i,0,n-1){
        cin >> trafficLights[i];
    }
    set<ll> street = {0,x};
    multiset<ll> longestPassage = {x-0};
    f(i,0,n-1){
        street.insert(trafficLights[i]);
        auto it = street.lower_bound(trafficLights[i]);
        it--;
        ll low = *it;
        ll high = *street.upper_bound(trafficLights[i]);
        longestPassage.erase(longestPassage.find(high - low));
        longestPassage.insert(trafficLights[i] - low);
        longestPassage.insert(high - trafficLights[i]);
        cout << *longestPassage.rbegin() << " ";
    }
    return 0;
}