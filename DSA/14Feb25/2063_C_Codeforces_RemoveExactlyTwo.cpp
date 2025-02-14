#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve() {
    ll n;
    cin >> n;
    
    if (n == 2) {
        // Edge case: Only one edge exists, no non-adjacent pair
        ll u, v;
        cin >> u >> v;
        return 0;
    }
    
    vector<ll> inDegree(n + 1, 0);
    set<pair<ll, ll>> edges;
    
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        edges.insert({u, v});
        edges.insert({v, u});  // Store bidirectional edges
        inDegree[u]++;
        inDegree[v]++;
    }

    ll ans = 0;
    vector<pair<ll, ll>> e;

    // Populate in-degree pairs
    for (ll i = 1; i <= n; i++) {
        e.push_back({inDegree[i], i});
    }

    // Sort in descending order of in-degree
    sort(e.rbegin(), e.rend());

    // Iterate through sorted nodes to find maximum sum
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (edges.find({e[i].second, e[j].second}) == edges.end()) {
                ans = max(ans, e[i].first + e[j].first - 1);
                break;
            }
        }
    }

    // Check direct edges for maximum sum
    for (auto x : edges) {
        ans = max(ans, inDegree[x.first] + inDegree[x.second] - 2);
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll res = solve();
        cout << res << endl;
    }
    return 0;
}
