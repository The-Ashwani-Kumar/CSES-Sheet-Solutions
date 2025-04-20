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

ll findNextGreater(multiset<ll> &heights, ll target){
    auto it = heights.upper_bound(target);
    if(it == heights.end()){
        return -1;
    }
    return *it;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> heights(n);
    f(i,0,n-1){
        cin >> heights[i];
    }
    
    multiset<ll> towers;
    f(i,0,n-1){
        ll nextGreater = findNextGreater(towers, heights[i]);
        if(nextGreater == -1){
            towers.insert(heights[i]);
        } else {
            towers.erase(towers.find(nextGreater));  // Use find to erase one occurrence
            towers.insert(heights[i]);
        }
    }
    cout << towers.size();
    return 0;
}