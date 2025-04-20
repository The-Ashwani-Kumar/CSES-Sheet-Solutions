#include<bits/stdc++.h>
#define ll long long
#define f(a,b)  for(ll i=a;i<=b;i++)
#define finc(a,b,gap)   for(ll i=a;i<=b;i+=gap)
#define rf(a,b) for(ll i=a;i>=b;i--)
#define v vector<ll>
#define vv vector<vector<ll>>
#define sortf(array) sort(array.begin(),array.end())
#define sortr(array) sort(array.rbegin(),array.rend())
using namespace std;
 
int main() 
{
    ll n, count=1;
    cin>>n;
    v arr(n);
    f(0,n-1){
        cin>>arr[i];
    }
    sortf(arr);
    f(1,n-1){
        if(arr[i-1]!=arr[i]){
            count++;
        }
    }
    cout<<count;
    return 0;
}