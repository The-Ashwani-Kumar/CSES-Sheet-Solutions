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

    string s;
    cin>>s;
    ll n = s.size();
    unordered_map<char,ll> freq;
    f(i,0,n-1){
        freq[s[i]]++;
    }
    ll odd = 0;
    for(auto f : freq){
        odd += (f.second & 1);
    }
    if(odd > 1){
        cout<<"NO SOLUTION";
    }
    else{
        string ans = "";
        char oddChar = ' ';
        for(auto f : freq){
            if(f.second & 1){
                oddChar = f.first;
            }
            f.second /= 2;
            while(f.second--){
                ans += f.first;
            }
        }
        string rev = ans;
        reverse(rev.begin(),rev.end()); 
        if(oddChar != ' '){
            ans += oddChar;
        }
        ans += rev;
        cout<<ans;
    }
}