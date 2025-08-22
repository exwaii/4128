#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector< pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> result(n);
    int start = 0;
    int end = n - 1;
    
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            result[n-1-i] = a[end--].second;
        } else {
            result[n-1-i] = a[start++].second;
        }
    }


    for (auto i : result) {
        cout << i + 1 << ' ';
    }
    // cout << '\n';
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
