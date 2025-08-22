#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    double n;
    cin >> n;
    cout << fixed << setprecision(7);
    double result = 0;
    for (double i = 1; i < n; i++) {
        result += n/i;
    }
    cout << n << '\n'; 
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
