#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n, 0);
    vector<long long> count(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        count[--l]++;
        if (r < n) {
            count[r]--;
        }
    }
    vector<long long> freq(n, 0);
    long long cum = 0;
    for (int i = 0; i < n; i++) {
        cum += count[i];
        freq[i] = cum;
    }

    sort(freq.begin(), freq.end());
    sort(a.begin(), a.end());
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i] * freq[i];
    }
    cout << result;
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
