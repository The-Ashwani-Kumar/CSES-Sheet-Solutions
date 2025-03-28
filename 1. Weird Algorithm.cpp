#include<bits/stdc++.h>
#define ll long long
#define f(i,a,b)	for(ll i=a;i<=b;i++)
#define rf(i,a,b)	for(ll i=a;i>=b;i--)
#define fg(i,a,b,gap)	for(ll i=a;i<=b;i+=gap)
#define v(dataType) vector<dataType>
#define vv(dataType) vector<vector<dataType>>
#define vp(dataType1,dataType2) vector<pair<dataType1,dataType2>>
#define sortV(s) sort(s.begin(),s.end())
#define sortR(s) sort(s.rbegin(),s.rend())
using namespace std;
string isSmaller(string &s, ll l, ll r, int k){
    while(l < r){
        if(s[l] > s[r]){
            if(k == 0){
                return "NO";
            }
            swap(s[l++],s[r--]);
            k--;
            return "YES";
        }        
        else if(s[l] < s[r]){
            return "YES";
        }
        else{
            l++, r--;
        }
    }
    return "YES";
}

int main(){
    // Redirect input and output to files
    freopen("inputf.in", "r", stdin);  // Read input from inputf.in
    freopen("outputf.out", "w", stdout);  // Write output to outputf.out

    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        string s;
        cin>>n>>k>>s;
        set<char>st(s.begin(),s.end());
        if(s[0] < s[n-1]){
            cout<<"YES\n";
        }
        else if(st.size() == 1){
            cout<<"NO\n";
        }
        else{
            if(n == 1 || k == 0){
                cout<<"NO\n";
            }
            else{
                cout<<isSmaller(s,0,n-1,k)<<endl;   
            }
        }
    }
}
