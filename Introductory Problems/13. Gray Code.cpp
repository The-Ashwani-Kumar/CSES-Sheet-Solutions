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
    v(string) grayCodes = {"0","1"};
    f(i,2,n){
        v(string) revGrayCodes = grayCodes;
        reverse(revGrayCodes.begin(),revGrayCodes.end());
        f(j,0,grayCodes.size()-1){
            grayCodes[j] = "0" + grayCodes[j];
        }  
        f(j,0,revGrayCodes.size()-1){
            revGrayCodes[j] = "1" + revGrayCodes[j];
        }
        grayCodes.insert(grayCodes.end(),revGrayCodes.begin(),revGrayCodes.end());
    }
    f(i,0,grayCodes.size()-1){
        cout<<grayCodes[i]<<endl;
    }
    return 0;
}