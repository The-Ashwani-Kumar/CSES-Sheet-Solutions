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
    set<ll> s;
    f(i,1,n){
        s.insert(i);
    }
    
    auto it = s.begin();
    while(s.size() > 1){
        it++;
        if(it == s.end()){
            it = s.begin();
        }
        auto killed = it;
        it++;
        if(it == s.end()){
            it = s.begin();
        }
        cout<<*killed<<" ";
        s.erase(killed);
    }
    cout<<*s.begin();
    return 0;
}