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
    vv(ll) customers(n,vector<ll>(3LL));
    f(i,0,n-1){
        cin>>customers[i][0]>>customers[i][1];
        customers[i][2] = i;
    }
    sortV(customers); 
    set<pair<ll,ll>> departures;
    ll roomNo = 1;
    departures.insert({customers[0][1],roomNo});
    v(ll) ans(n);
    ans[customers[0][2]] = 1;

    f(i,1,n-1){
        auto it = departures.begin();
        ll lastDeparture = it->first;;
        ll lastRoomNo = it->second;
        if(customers[i][0] > lastDeparture){
            departures.insert({customers[i][1],lastRoomNo});
            ans[customers[i][2]] = lastRoomNo;
            departures.erase(it);
        }
        else{
            roomNo++;
            departures.insert({customers[i][1],roomNo});
            ans[customers[i][2]] = roomNo;
        }
    }
    cout<<roomNo<<endl;
    f(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    return 0;
}