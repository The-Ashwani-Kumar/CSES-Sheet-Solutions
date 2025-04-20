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
    v(ll) arrival(n), departure(n);
    f(i,0,n-1){
        cin>>arrival[i]>>departure[i];
    }
    sortV(arrival);
    sortV(departure);
    ll i=0, j=0, count=0, maxCount=1;
    while(i < n && j < n){
        if(arrival[i] < departure[j]){
            count++, i++;
        }
        else{
            count--, j++;
        }
        maxCount = max(maxCount, count);
    }
    cout<<maxCount;
    return 0;
}