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

ll findMinDifference(ll i, ll group1, ll group2, v(ll) &appleWeights){
    if(i < 0){
        return abs(group1 - group2);
    }
    ll includeToGroup1 = findMinDifference(i-1,group1+appleWeights[i],group2,appleWeights);
    ll includeToGroup2 = findMinDifference(i-1,group1,group2+appleWeights[i],appleWeights);
    return min(includeToGroup1, includeToGroup2);
}

int main(){

    ll n;
    cin>>n;
    v(ll) appleWeights(n);
    f(i,0,n-1){
        cin>>appleWeights[i];
    }
    cout<<findMinDifference(n-1,0,0,appleWeights)<<endl;
    return 0;
}