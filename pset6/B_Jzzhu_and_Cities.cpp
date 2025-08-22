#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

typedef pair<int, int> edge;  // (distance , vertex)

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<edge>> adj(n + 1);

    vector<array<int, 3>> roads(m);
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        roads[i] = {u, v, x};
        adj[u].push_back({x, v});
        adj[v].push_back({x, u});
        // cout << "done\n";
    }

    vector<array<int, 2>> trains(k);
    for (int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;
        trains[i] = {y, s};
        adj[1].push_back({y, s});
        adj[s].push_back({y, 1});
        // cout << "done2\n";
    }

    // djikstras to find distance to every city
    vector<ll> dist(n + 1, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        // cout << d << ' ' << v << '\n';
        if (dist[v] != LLONG_MAX) {
            continue;
        }
        dist[v] = d;
        for (edge next : adj[v]) {
            int u = next.second, w = next.first;
            if (dist[u] == LLONG_MAX) {
                pq.emplace(d + w, u);
            }
        }
    }

    vector<bool> roadable(n + 1);
    for (const auto& [u, v, x] : roads) {
        if (dist[u] + x == dist[v]) {
            roadable[v] = 1;
        }
        if (dist[v] + x == dist[u]) {
            roadable[u] = 1;
        }
    }
    int result = 0;

    for (auto& [y, s] : trains) {
        if (y > dist[s]) { // train is useless
            result++;
        } else {
            if (roadable[s]) {
                result++; // can get there by train
            } else {
                roadable[s] = 1; // lets call the first train a road
            }
        }
    }
    cout << result;
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
