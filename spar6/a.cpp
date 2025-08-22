#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k = n - m;
    sort(a.begin(), a.end());
    int result = INT_MIN;
    for (int i = 0; i < k; i++) {
        int test = a[i] + a[2 * k - i - 1];
        // cout << test << ' ';
        if (test > result) {
            result = test;
        }
    }
    for (int i = (k > 0 ? 2 * k : 0); i < n; i++) {
    // for (int i = 2 * k; i < n; i++) {
    // cout << a[i] << ' ';
        if (a[i] > result) {
            result = a[i];
        }
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
