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
    f(k,1,n){
        ll total = k*k*(k*k-1)/2;
        if(k==1){
            cout<<0<<endl;
            continue;
        }
        ll attack = 4*(k-1)*(k-2);
        cout<<total-attack<<endl;
    }
}