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

void towerOfHanoi(ll n, ll source, ll destination, ll auxiliary, vp(ll,ll) &moves){
    if(n == 0){
        return;
    }
    towerOfHanoi(n-1, source, auxiliary, destination, moves);
    moves.push_back({source, destination});
    towerOfHanoi(n-1, auxiliary, destination, source, moves);
}

int main(){
    ll n;
    cin>>n;
    vp(ll,ll) moves;
    towerOfHanoi(n, 1, 3, 2, moves);
    cout<<moves.size()<<endl;
    f(i,0,moves.size()-1){
        cout<<moves[i].first<<" "<<moves[i].second<<endl;
    }
    return 0;
}