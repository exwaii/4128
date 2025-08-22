#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;

    int dp[250][250];
    // let dp[r][c] = number of ways to fill the last r rows
    // if all but c columns have a 1 in the existing n - r rows
    // dp[n][0] is our solution
    // dp[i][0] = 


    // if going across columns, to fill up the next column you have k^n - (k-1)^n ways
    // all ways - all not 1s
    
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
