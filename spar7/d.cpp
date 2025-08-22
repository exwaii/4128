#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<pi> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].first;
        s[i].second = i;
    }
    sort(s.begin(), s.end(), [](pi a, pi b) { return a.first < b.first; });
    vector<ll> prefix(n);
    vector<bool> yes(n);
    prefix[0] = s[0].first;
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + s[i].first;
    }

    // for (auto i : prefix) {
    //     cout << i << '\n';
    // }
    yes[n - 1] = true;
    for (int i = 0; i < n - 1; i++) {
        if (prefix[i] >= s[i + 1].first) {
            yes[i] = true;
        } else {
            yes[i] = false;
        }
    }

    bool curr = true;
    s[n - 1].first = true;
    for (int i = n - 2; i >= 0; i--) {
        curr &= yes[i];
        s[i].first = curr;
        // cout << curr << '\n';
    }
    // for (pi x : s) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    // cout << "\n\n";
    sort(s.begin(), s.end(), [](pi a, pi b) { return a.second < b.second; });

    // for (pi x : s) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    for (pi x : s) {
        if (x.first) {
            cout << 'W';
        } else {
            cout << 'L';
        }
        // cout << '\n';
    }
    cout << '\n';
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
