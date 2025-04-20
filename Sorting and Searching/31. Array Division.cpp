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

bool isPossible(ll mid, v(ll) &arr, ll n, ll k){
    ll sum = 0, partition = 1;
    f(i,0,n-1){
        sum += arr[i];
        if(sum > mid){
            partition++;
            sum = arr[i];
        }
    }
    return partition <= k;
}

int main(){

    ll n,k, low = 0, high = 1e18, ans = 1e18;
    cin>>n>>k;
    v(ll) arr(n);
    f(i,0,n-1){
        cin>>arr[i];
        low = max(low,arr[i]);
    }
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(isPossible(mid,arr,n,k)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<ans;
    return 0;
}