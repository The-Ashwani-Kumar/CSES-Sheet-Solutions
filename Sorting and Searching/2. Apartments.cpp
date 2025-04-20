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

    ll applicants, appartments, allowedDifference;
    cin>>applicants>>appartments>>allowedDifference;
    v(ll) desired(applicants), appartmentSize(appartments);
    f(i,0,applicants-1){
        cin>>desired[i];
    }
    f(i,0,appartments-1){
        cin>>appartmentSize[i];
    }
    sortV(desired);
    sortV(appartmentSize);
    ll count=0;
    ll i=0,j=0;
    while(i < applicants && j < appartments){
        if(abs(desired[i]-appartmentSize[j]) <= allowedDifference){
            count++, i++, j++;
        }
        else if(desired[i] < appartmentSize[j]){
            i++;
        }
        else{
            j++;
        }
    }
    cout<<count;
    return 0;
}