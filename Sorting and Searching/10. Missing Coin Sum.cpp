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
    v(ll) coins(n);
    f(i,0,n-1){
        cin>>coins[i];
    }
    sortV(coins);
    ll sum = 0, num = 1;
    f(i,0,n-1){
        sum += coins[i];
        if(coins[i] > num){
            break;
        }
        num = sum + 1;
    }
    cout<<num;
    return 0;
}