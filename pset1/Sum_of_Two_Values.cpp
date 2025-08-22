#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n); 
    map<int, int> r;
    for (int i = 0; i < n; i ++) {
        cin >> a[i]; 
        r[x - a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (r.find(a[i]) != r.end() && r[a[i]] != i) {
            cout << i + 1 << ' ' << r[a[i]] + 1 << '\n';
            exit(0);
        }
    }
    cout << "IMPOSSIBLE\n"; 
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
