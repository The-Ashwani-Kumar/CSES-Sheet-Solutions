#include<bits/stdc++.h>
#define ll long long
#define fi(a,b)  for(ll i=a;i<=b;i++)
#define fj(a,b)  for(ll j=a;j<=b;j++)
#define fk(a,b)  for(ll k=a;k<=b;k++)
#define finc(a,b,gap)   for(ll i=a;i<=b;i+=gap)
#define rf(a,b) for(ll i=a;i>=b;i--)
#define p pair<ll,ll>
#define v vector<ll>
#define vv vector<vector<ll>>
#define vp vector<pair<ll,ll>>
#define sortf(array) sort(array.begin(),array.end()
#define sortr(array) sort(array.rbegin(),array.rend())
using namespace std;
 
ll findRounds(ll n, unordered_map<int,int>&mp){
	ll round=1, i=1;
	while(i<=n){
		ll index = -1;
		while(i<=n && index < mp[i]){
			index = mp[i];
			mp.erase(i);
			i++;
		}
		if(i>n){
			break;
		}
		round++;
	}
	return round;
}
 
int main() 
{
	ll n,m;
	cin>>n>>m;
	unordered_map<int,int>mp;
	v arr(n);
	fi(0,n-1){
		cin>>arr[i];
		mp[arr[i]] = i+1;
	}
	ll inversions = 1;
	fi(2,n){
		if(mp[i-1]>mp[i]){
			inversions++;
		}
	}
	fi(0,m-1){
		ll a,b;
		cin>>a>>b;
		int elementA = arr[a-1];
		int elementB = arr[b-1];
		set<pair<int,int>>uniquePairs;
		if(elementA>1){
			uniquePairs.insert({elementA-1,elementA});
		}
		if(elementA<n){
			uniquePairs.insert({elementA,elementA+1});
		}
		if(elementB>1){
			uniquePairs.insert({elementB-1,elementB});
		}
		if(elementB<n){
			uniquePairs.insert({elementB,elementB+1});
		}
		for(auto unique : uniquePairs){
			int first = unique.first;
			int second = unique.second;
			if(mp[first]>mp[second]){
				inversions--;
			}
		}
 
		swap(arr[a-1],arr[b-1]);
		mp[arr[a-1]] = a;
		mp[arr[b-1]] = b;
		
		for(auto unique : uniquePairs){
			int first = unique.first;
			int second = unique.second;
			if(mp[first]>mp[second]){
				inversions++;
			}
		}
		cout<<inversions<<endl;
	}
	
	return 0;
}