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
        ll n, base = 9, digit = 1;
        cin>>n;
        while(n > base*digit){
            n -= base * digit;
            base *= 10;
            digit++;
        }
        ll startingNumber = (ll)pow(10, digit-1) + (n-1)/digit;
        ll digitIndex = (n-1) % digit;
        string number = to_string(startingNumber);
        cout<<number[digitIndex]<<endl;
    }
}