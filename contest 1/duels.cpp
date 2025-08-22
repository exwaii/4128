#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> j(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> j[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(j.begin(), j.end());
    sort(t.begin(), t.end());

    int wj_max = 0;
    int i = 0, k = 0;
    while (i < n && k < n) {
        if (j[i] > t[k]) {
            wj_max += 2;
            k++;
        } else if (j[i] == t[k]) {
            wj_max++;
            k++;
        }
        i++;
    }

    int wt_max = 0;
    // i = n - 1;
    // k = n - 1;
    // while (i >= 0 && k >= 0) {
    //     if (t[i] > j[k]) {
    //         wt_max += 2;
    //         k++;
    //     } else if (j[i] == t[k]) {
    //         wt_max++;
    //         k++;
    //     }
    //     i++;
    // }
    cout << wt_max << ' ' << wj_max << '\n'; 
    if (wt_max >= n && wj_max >= n) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
