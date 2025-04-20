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

ll calculateTicketPrice(multiset<ll> &tickets, ll customer) {
    auto it = tickets.upper_bound(customer); // Find the first ticket strictly greater than customer
    if (it == tickets.begin()) {
        return -1; // No ticket is less than or equal to the customer's price
    }
    --it; // Move to the largest ticket <= customer
    ll ticketPrice = *it;
    tickets.erase(it); // Remove the ticket
    return ticketPrice;
}

int main() {
    ll n, m, ticket, customer;
    cin >> n >> m;
    multiset<ll> tickets;
    f(i, 0, n - 1) {
        cin >> ticket;
        tickets.insert(ticket);
    }
    f(i, 0, m - 1) {
        cin >> customer;
        cout << calculateTicketPrice(tickets, customer) << endl;
    }
    return 0;
}
