#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

// int dfs(int curr, vector<int> &visited, vector<vector<int>> &c, int water, int n) {
//     // water is defined to be the level that water is below
//     if (curr == 2 * n) {
//         // cout << curr << ' ' << water << '\n';
//         return true;
//     }
//     int level = curr % n;
//     if (water > level) {
//         return false;
//     }
//     // if (visited[curr]) {
//     //     return false;
//     // }
//     // visited[curr] = 1;
//     for (int i : c[curr]) {
//         if (dfs(i, visited, c, water + 1, n)) {
//             // cout << curr << ' ' << water << '\n';
//             return true;
//         }
//     }
//     return false;
// }

void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> l(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    vector<char> r(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    vector<vector<int>> c(2 * n + 1, vector<int>(0));
    for (int i = 0; i < n; i++) {  // left
        if (l[i] != 'X') {
            if (i > 0 && l[i - 1] != 'X') {
                c[i].push_back(i - 1);  // can go down
            }
            if (i < n - 1 && l[i + 1] != 'X') {
                c[i].push_back(i + 1);  // can go up
            }
            if (i == n - 1) {
                c[i].push_back(2 * n);  // can escape by going up
            }
            if (i + k < n && r[i + k] != 'X') {
                c[i].push_back(n + i + k);  // can jump to opp wall
            }
            if (i + k >= n) {
                c[i].push_back(2 * n);  // can jump to escape
            }
        }
    }
    for (int i = 0; i < n; i++) {  // right
        if (r[i] != 'X') {
            if (i > 0 && r[i - 1] != 'X') {
                c[n + i].push_back(n + i - 1);  // can go down
            }
            if (i < n - 1 && r[i + 1] != 'X') {
                c[n + i].push_back(n + i + 1);  // can go up
            }
            if (i == n - 1) {
                c[n + i].push_back(2 * n);  // can escape by going up
            }
            if (i + k < n && l[i + k] != 'X') {
                c[n + i].push_back(i + k);  // can jump to opp wall
            }
            if (i + k >= n) {
                c[n + i].push_back(2 * n);  // can jump to escape
            }
        }
    }

    // bfs

    vector<bool> visited(2 * n, false);
    queue<pi> q;
    q.emplace(0, 0);
    visited[0] = true;

    while (!q.empty()) {
        auto [v, t] = q.front();
        q.pop();
        for (int next: c[v]) {
            if (next == 2 * n) {
                cout << "YES\n";
                return;
            }
            int level = next % n;
            if (!visited[next] && t < level) {
                q.emplace(next, t + 1);
                visited[next] = true;
            }
        }
    }
    
    cout << "NO\n";
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
