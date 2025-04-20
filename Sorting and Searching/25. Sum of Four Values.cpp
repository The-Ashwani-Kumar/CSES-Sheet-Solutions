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

    ll n,target;
    cin>>n>>target;
    vp(ll,ll) arr(n);
    f(i,0,n-1){
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    sortV(arr);
    f(i,0,n-4){
        ll sum = target - arr[i].first;
        f(j,i+1,n-3){
            sum -= arr[j].first;
            ll low = j+1, high = n-1;
            while(low < high){
                ll total = arr[low].first + arr[high].first;
                if(sum == total){
                    cout<<arr[i].second<<" "<<arr[j].second<<" "<<arr[low].second<<" "<<arr[high].second;
                    return 0;
                }
                if(total < sum){
                    low++;
                }
                else{
                    high--;
                }
            }
            sum += arr[j].first;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}