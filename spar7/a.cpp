#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = min(a, b);
    x = min(x, c);
    cout << fixed << setprecision(7);
    cout << ((long double) x)/((long double) sqrt(2)) << '\n';
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
