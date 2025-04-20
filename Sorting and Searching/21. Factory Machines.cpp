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

bool isPossible(ll create, ll products, ll machines, v(ll) &timeTaken){
    ll totalProducts = 0;
    f(i,0,machines-1){
        totalProducts += create / timeTaken[i];
        if(totalProducts >= products) return true;
    }
    return false;
}

int main(){
    ll machines, products;
    cin >> machines >> products;
    v(ll) timeTaken(machines);
    f(i,0,machines-1){
        cin >> timeTaken[i];
    }
    sortV(timeTaken);
    ll low = 1, high = timeTaken[0] * products, ans = -1;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(isPossible(mid, products, machines, timeTaken)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}