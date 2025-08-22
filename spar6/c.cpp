#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }

    vector<vector<pair<int, int>>> g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({time[u], v});
        g[v].push_back({time[v], u});
    }

    vector<ll> dist(n, LLONG_MAX);
    vector<ll> pred(n);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    

}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
