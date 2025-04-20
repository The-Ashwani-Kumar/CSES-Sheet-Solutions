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
    ll n, rounds = 0;
    cin>>n;
    v(ll) arr(n);
    unordered_map<ll,bool> present;
    f(i,0,n-1){
        cin>>arr[i];
    }
    f(i,0,n-1){
        present[arr[i]] = true;
        if(present.find(arr[i]-1) == present.end()){
            rounds++;
        }
    }
    cout<<rounds;
    return 0;
}