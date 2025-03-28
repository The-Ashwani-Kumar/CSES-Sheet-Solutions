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
    ll sum = (n*(n+1))/2;
    if(sum & 1){
        cout<<"NO\n";
    }
    else{
        v(ll) set1, set2;
        ll half = sum/2;
        rf(i,n,1){
            if(half >= i){
                set1.push_back(i);
                half -= i;
            }
            else{
                set2.push_back(i);
            }
        }
        cout<<"YES\n";
        cout<<set1.size()<<endl;
        f(i,0,set1.size()-1){
            cout<<set1[i]<<" ";
        }
        cout<<endl;
        cout<<set2.size()<<endl;    
        f(i,0,set2.size()-1){
            cout<<set2[i]<<" ";
        }
        cout<<endl;
    }
}