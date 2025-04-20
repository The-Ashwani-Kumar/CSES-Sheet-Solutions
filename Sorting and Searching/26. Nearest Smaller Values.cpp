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
    v(ll) arr(n);
    f(i,0,n-1){
        cin>>arr[i];
    }
    stack<ll> st;
    f(i,0,n-1){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            cout<<"0 ";
        }
        else{
            cout<<st.top()+1<<" ";
        }
        st.push(i);
    }
    return 0;
}