#include <bits/stdc++.h>

using namespace std;
#define ll long long

int yield(int r1, int r2, int c1, int c2, vector<vector<int>> &P) {
    return P[r2][c2] - P[r1 - 1][c2] - P[r2][c1 - 1] + P[r1 - 1][c1 - 1];
}

static int dp[61][61][61][61] = {0};

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> R(n + 1, vector<int>(m + 1, 0)), P(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int curr;
            cin >> curr;
            if (curr > t) {
                cout << -1 << '\n';
                return;
            }
            R[i][j] = R[i][j - 1] + curr;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            P[i][j] = P[i - 1][j] + R[i][j];
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << P[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int r1 = 1; r1 <= n; ++r1) {
        for (int r2 = r1; r2 <= n; ++r2) {
            for (int c1 = 1; c1 <= m; ++c1) {
                for (int c2 = c1; c2 <= m; ++c2) {
                    if (yield(r1, r2, c1, c2, P) <= t)
                        dp[r1][r2][c1][c2] = 0;
                    else
                        dp[r1][r2][c1][c2] = __INT_MAX__;
                }
            }
        }
    }

    for (int height = 1; height <= n; height++) {
        for (int length = 1; length <= m; length++) {
            for (int r1 = 1; r1 + height - 1 <= n; r1++) {
                int r2 = r1 + height - 1;
                for (int c1 = 1; c1 + length - 1 <= m; c1++) {
                    int c2 = c1 + length - 1;
                    if (dp[r1][r2][c1][c2] == 0) { // if < T
                        continue;
                    }
                    // otherwise we must cut
                    // horizontal cut
                    for (int mid = r1; mid < r2; mid++) { // mid == r2 is no cut
                        int cost = dp[r1][mid][c1][c2] + dp[mid+1][r2][c1][c2] + length;
                        dp[r1][r2][c1][c2] = min(dp[r1][r2][c1][c2], cost); 
                    }
                    // vert cut
                     for (int mid = c1; mid < c2; mid++) { // mid == r2 is no cut
                        int cost = dp[r1][r2][c1][mid] + dp[r1][r2][mid+1][c2] + height;
                        dp[r1][r2][c1][c2] = min(dp[r1][r2][c1][c2], cost); 
                    }
                }
            }
        }
    }
    cout << (dp[1][n][1][m] != __INT_MAX__ ? dp[1][n][1][m] : -1) << '\n';  
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
