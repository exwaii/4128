#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int n, m, k, c;
    cin >> n >> m >> k >> c;
    int h[40][40];  // h[i][j]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h[i][j];
        }
    }
    set<int> not_alone;

    int friends[k][2];
    for (int i = 0; i < k; i++) {
        cin >> friends[i][0] >> friends[i][1];
        not_alone.insert(--friends[i][0]);
        not_alone.insert(--friends[i][1]);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (not_alone.find(i) != not_alone.end()) {
            continue;
        }
        int best = INT_MIN;
        for (int j = 0; j < m; j++) {
            if (h[i][j] > best) {
                best = h[i][j];
            }
        }
        result += best;
    }

    for (auto p : friends) {
        int best = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (h[p[0]][i] + h[p[1]][j] - c * abs(i - j) > best) {
                    best = h[p[0]][i] + h[p[1]][j] - c * abs(i - j);
                }
            }
        }
        result += best;
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
