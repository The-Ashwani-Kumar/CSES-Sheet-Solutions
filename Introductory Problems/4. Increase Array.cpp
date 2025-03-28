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

    ll n, operations = 0;
    cin>>n;
    v(ll) array(n);
    f(i,0,n-1){
        cin>>array[i];
    }
    f(i,1,n-1){
        if(array[i-1] > array[i]){
            ll difference = array[i-1] - array[i];
            array[i] += difference;
            operations += difference;
        }
    }
    cout<<operations<<endl;
}