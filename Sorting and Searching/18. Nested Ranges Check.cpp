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

    ll n;
    cin>>n;
    vv(ll) ranges(n, vector<ll>(3));
    f(i,0,n-1){
        cin>>ranges[i][0]>>ranges[i][1];
        ranges[i][2] = i;
    }
    sort(ranges.begin(), ranges.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[0] < b[0] || (a[0]==b[0] && a[1] > b[1]);
    });
    v(ll) contains(n,0), contained(n,0);
    ll minRight = LLONG_MAX;
    rf(i,n-1,0){
        if(ranges[i][1] >= minRight){
            contains[ranges[i][2]] = 1;
        }
        minRight = min(minRight, ranges[i][1]);
    }
    ll maxRight = LLONG_MIN;
    f(i,0,n-1){
        if(ranges[i][1] <= maxRight){
            contained[ranges[i][2]] = 1;
        }
        maxRight = max(maxRight, ranges[i][1]);
    }
    f(i,0,n-1){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    f(i,0,n-1){
        cout<<contained[i]<<" ";
    }
    return 0;
}