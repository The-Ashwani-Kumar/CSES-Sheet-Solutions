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

    ll n,target;
    cin>>n>>target;
    vp(ll,ll) arr(n);
    f(i,0,n-1){
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    sortV(arr);
    f(i,0,n-3){
        ll low = i+1, high = n-1;
        ll sum = target - arr[i].first;
        while(low < high){
            ll total = arr[low].first + arr[high].first;
            if(sum == total){
                cout<<arr[i].second<<" "<<arr[low].second<<" "<<arr[high].second;
                return 0;
            }
            if(total < sum){
                low++;
            }
            else{
                high--;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}