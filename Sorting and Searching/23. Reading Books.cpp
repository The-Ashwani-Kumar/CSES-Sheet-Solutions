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

    ll books, timeTaken, totalTime = 0, maxTime = 0;
    cin>>books;
    f(i,0,books-1){
        cin>>timeTaken;
        totalTime += timeTaken;
        maxTime = max(maxTime, timeTaken);
    }
    cout<<max(totalTime, 2*maxTime);
    return 0;
}