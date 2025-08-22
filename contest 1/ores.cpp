#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long i, g, d;
    cin >> i >> g >> d; 
    // steve starts first
    long long s = i + (d+1)/2;
    long long a = g + d/2;
    if (s > a) {
        cout << "Steve"; 
    } else {
        cout << "Alex";
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
