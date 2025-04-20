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
    v(ll) arr(n);
    f(i,0,n-1){
        cin>>arr[i];
    }
    sortV(arr);
    ll median = arr[n/2];
    ll minOperations = 0;
    f(i,0,n-1){
        minOperations += abs(arr[i]-median);
    }
    cout<<minOperations;
    return 0;
}