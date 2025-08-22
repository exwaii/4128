#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

typedef pair<int, int> edge;  // (distance , vertex)

void solve() {
    int n;
    cin >> n;
    ll dist[500][500];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        q[i]--;
    }

    ll result[500];
    vector<int> intact;
    for (int i = 0; i < n; i++) {  // shortest path using x_n to x_n-1-i
        int curr = q[n - 1 - i];
        intact.push_back(curr);
        result[i] = 0;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                dist[u][v] = min(dist[u][curr] + dist[curr][v], dist[u][v]);
            }
        }
        for (int u : intact) {
            for (int v : intact) {
                result[i] += dist[u][v];
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) {
            cout << ' ';
        }
        cout << result[i];
    }
    cout << '\n';
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
