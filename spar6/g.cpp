#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

ll gcd(ll a, ll b) {
    if (b == 0) {return a;}
    return gcd(b, a % b);
}

void solve() {
    ll a, b, t;
    cin >> a >> b >> t;
    // cout << gcd(a, b);
    ll lcm = a * b / gcd(a, b);
    if (lcm <= t) {
        cout << "yes\n"; 
    } else {
        cout << "no\n";
    }
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
