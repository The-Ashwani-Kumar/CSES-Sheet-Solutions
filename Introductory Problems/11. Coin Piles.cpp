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

    ll t;
    cin>>t;
    while(t--){
        ll pile_a, pile_b;
        cin>>pile_a>>pile_b;
        if((pile_a*2-pile_b) < 0 || (pile_b*2-pile_a) < 0 || (pile_a*2-pile_b)%3 != 0 || (pile_b*2-pile_a)%3 != 0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}