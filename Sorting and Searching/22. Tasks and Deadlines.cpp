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
    vp(ll,ll) tasks(n);
    f(i,0,n-1){
        cin>>tasks[i].first>>tasks[i].second;
    }
    sort(tasks.begin(),tasks.end(),[](pair<ll,ll> a, pair<ll,ll> b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    ll maximumReward = 0, currentTime = 0;
    f(i,0,n-1){
        currentTime += tasks[i].first;
        maximumReward += tasks[i].second - currentTime;
    }
    cout<<maximumReward<<endl;
    return 0;
}