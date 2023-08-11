#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, coins;
    cin >> n;
    cin >> coins;

    vector<ll> cost(n);
    vector<ll> sell(n);

    for (ll i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    for (ll i = 0; i < n; ++i) {
        cin >> sell[i];
    }

    vector<pair<ll, ll>> pair;
    for (ll i = 0; i < n; ++i) {
        if (cost[i] <= sell[i]) {
            pair.push_back(make_pair(cost[i], sell[i]));
        }
    }

    sort(pair.begin(), pair.end());
    ll profit = 0;

    for (ll i = 0; i < pair.size(); ++i) {
        if (coins < pair[i].first) {
            break;
        }
        profit += pair[i].second - pair[i].first;
        coins += pair[i].second - pair[i].first;
    }

    cout << profit << endl;

    return 0;
}