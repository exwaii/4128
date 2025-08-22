#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, p, cost = 0;
    cin >> n;
    int curr_min = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a >> p;
        curr_min = p < curr_min ? p : curr_min;
        cost += curr_min * a;   
    }
    cout << cost << '\n';
}

int main() {
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
