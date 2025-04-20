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

    ll n,x;
    cin>>n>>x;
    vp(ll,ll) arr(n);
    f(i,0,n-1){
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    sortV(arr);
    ll i=0,j=n-1;
    while(i < j){
        ll sum = arr[i].first + arr[j].first;
        if(sum == x){
            cout<<arr[i].second<<" "<<arr[j].second;
            return 0;
        }
        if(sum < x){
            i++;
        }
        else{
            j--;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}