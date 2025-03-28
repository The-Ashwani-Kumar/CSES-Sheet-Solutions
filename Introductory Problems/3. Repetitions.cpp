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
    string DNA_Squence;
    cin>>DNA_Squence;
    ll maxCount = 1, count = 1, n = DNA_Squence.size();
    f(i,1,n-1){
        if(DNA_Squence[i-1] == DNA_Squence[i]){
            count++;
        }
        else{
            count = 1;
        }
        maxCount = max(maxCount, count);
    }
    cout<<maxCount<<endl;
}