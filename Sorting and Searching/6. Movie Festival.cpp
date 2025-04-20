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

    ll n,start,end;
    cin>>n;
    vp(ll,ll) duration(n);
    f(i,0,n-1){
        cin>>start>>end;
        duration[i] = {start, end};
    }
    sort(duration.begin(), duration.end(), [](pair<ll,ll> a, pair<ll,ll> b){
        return a.second < b.second;
    });
    ll movies = 0, lastEnd = 0;
    f(i,0,n-1){
        if(duration[i].first >= lastEnd){
            movies++;
            lastEnd = duration[i].second;
        }
    }
    cout<<movies;
    return 0;
}