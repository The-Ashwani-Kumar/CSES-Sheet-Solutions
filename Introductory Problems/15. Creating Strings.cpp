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

void findPermutations(int i, int n, string &s, set<string> &uniqueSubstrings){
    if(i == n){
        uniqueSubstrings.insert(s);
        return;
    }
    for(int j=i;j<n;j++){
        if(i != j && s[i] == s[j]) continue; // Skip duplicates
        swap(s[i], s[j]);
        findPermutations(i+1, n, s, uniqueSubstrings);
        swap(s[i], s[j]); 
    }
}

int main(){
    string s;
    cin>>s;
    set<string> uniqueSubstrings;
    sortV(s);
    findPermutations(0, s.size(), s, uniqueSubstrings);
    cout<<uniqueSubstrings.size()<<endl;
    for(const auto &str : uniqueSubstrings){
        cout<<str<<endl;
    }
}