#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<ll, ll>

ll square(ll a) {
    return a * a; 
}
void solve() {
    int n;
    cin >> n;
    vector<pi> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
    }
    pi a, b;
    cin >> a.first >> a.second >> b.first >> b.second;
    ll ab = square(a.first - b.first) + square(a.second - b.second);
    // cout << ab << '\n';  
    for (auto [x, y]: c) {
        // cout << x << ' ' << y << '\n';
        ll dist = square(x - b.first) + square(y - b.second);
        if (dist <= ab) {
            cout << "NO\n";
            return; 
        }
    }
    cout << "YES\n"; 
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
