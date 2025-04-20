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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,k;
    cin>>n>>k;
    v(ll) arr(n);
    f(i,0,n-1){
        cin>>arr[i];
    }
    
    ll left = 0,count = 0, distinct_count = 0;
    map<ll,ll> freq;
    
    f(right,0,n-1){
        if(freq.find(arr[right]) == freq.end() || freq[arr[right]] == 0){
            distinct_count++;
        }
        freq[arr[right]]++;
        
        while(distinct_count > k){
            freq[arr[left]]--;
            if(freq[arr[left]] == 0){
                distinct_count--;
            }
            left++;
        }
        count += (right - left + 1);
    }
    
    cout<<count;
    return 0;
}