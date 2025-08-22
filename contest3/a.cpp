#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int n, m, k, c, d;
    cin >> n >> m >> k >> c >> d;
    int h[50], p[50];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    // any edge from u -> v has cost
    // d(h_v - h_u) if h_u < h_v
    // -c(h_u - h_v) if h_v < h_u
    // want to make every edge non negative
    // add c(h_u - h_v) to every edge
    // edge is now
    // d(h_v - h_u) + c(h_u - h_v) if h_u < h_v
    // 0 else
    // (d-c)(max(h_v-h_u, 0))

    vector<vector<pair<ll, ll>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(
            {v,
             (d - c) * (max(h[v] - h[u], 0))});
        adj[v].push_back(
            {u,
             (d - c) * (max(h[u] - h[v], 0))});
    }

    // floyd warshall for shortest dist between every two vertices
    static ll dist[50][50];

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            dist[u][v] = LLONG_MAX;
        }
    }

    for (int i = 0; i < n; i++) {
        for (pi a : adj[i]) {
            dist[i][a.first] = a.second;
        }
    }

    for (int u = 0; u < n; ++u) {
        dist[u][u] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int u = 0; u < n; u++) {
            if (dist[u][i] == LLONG_MAX) {
                continue;
            }
            for (int v = 0; v < n; v++) {
                if (dist[i][v] == LLONG_MAX) {
                    continue;
                }
                dist[u][v] = min(dist[u][v], dist[u][i] + dist[i][v]);
            }
        }
    }

    // bitmask dp[mask][v], cheapest way to end at v having visited all nations in mask
    // we want the start with dp[p[u]][u] = - ch[u] so we can add ch[v] later and recover original cost 
    // by subtracting c(h_u - h_v) 

    static ll dp[1 << 15][50];

    for (int i = 0; i < (1 << k); i++) {
        for (int v = 0; v < n; v++) {
            dp[i][v] = LLONG_MAX;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[1 << p[i]][i] = -1LL * c * h[i];
    }

    for (int mask = 1; mask < 1 << k; mask++) {
        for (int u = 0; u < n; u++) {
            if (dp[mask][u] == LLONG_MAX) {
                continue;
            }
            for (int v = 0; v < n; v++) {
                if (dist[u][v] == LLONG_MAX) {
                    continue;
                }
                int new_mask = mask | (1 << p[v]);
                if (dist[u][v] + dp[mask][u] < dp[new_mask][v]) {
                    dp[new_mask][v] = dist[u][v] + dp[mask][u];
                }
            }
        }
    }
    ll result = LLONG_MAX;
    int all_mask = (1 << k) - 1;
    for (int i = 0; i < n; i++) {
        if (dp[all_mask][i] == LLONG_MAX) {
            continue;
        }
        if (dp[all_mask][i] + c * h[i] < result) {
            result = dp[all_mask][i] + c * h[i];
        }
    }
    if (result == LLONG_MAX) {
        cout << "impossible\n";
        return;
    }
    cout << result << '\n';
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
