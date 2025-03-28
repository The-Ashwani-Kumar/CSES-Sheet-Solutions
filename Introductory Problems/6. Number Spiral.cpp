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
        ll row, col;
        cin>>row>>col;
        if(row >= col){
            if(row & 1){
                cout<<(((row-1)*(row-1)) + col)<<endl;
            }
            else{
                cout<<(row*row - col + 1)<<endl;
            }
        }
        else{
            if(col & 1){
                cout<<(col*col - row + 1)<<endl;
            }
            else{
                cout<<((col-1)*(col-1) + row)<<endl;
            }
        }
    }
}