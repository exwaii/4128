#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<ll> m(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    // let t[i] = number of marks at any day
    // t[i] = below + m[i] + 1
    // want to minimise t[i]

    // we know:
    // t[i] >= m[i] + 1 always
    // t[i] = t[i-1] or t[i-1] + 1

    vector<ll> t(n, 0);
    t[0] = m[0] + 1;
    for (int i = 1; i < n; i++) {
        t[i] = max(m[i] + 1, t[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        t[i] = max(t[i + 1] - 1, t[i]);
    }

    ll result = 0;
    for (int i = 0; i < n; i++) {
        result += t[i] - m[i] - 1;
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
