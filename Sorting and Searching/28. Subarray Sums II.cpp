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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,x;
    cin>>n>>x;
    v(ll) arr(n);
    f(i,0,n-1){
        cin>>arr[i];
    }
    ll sum = 0, count = 0;
    map<ll,ll> mp;
    mp[0] = 1;
    f(i,0,n-1){
        sum += arr[i];
        if(mp.find(sum-x) != mp.end()){
            count += mp[sum-x];
        }
        mp[sum]++;
    }
    cout<<count;
    return 0;
}