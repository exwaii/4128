#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    multiset<int> c;
    // store finishing times
    // for each activity
    // if there is space add it
    // if not find the activity that ends right before it starts
    int amount = 0;
    for (int i = 0; i < n; i++) {
        auto it = c.lower_bound(a[i].first);
        if (it != c.begin()) {
            c.erase(--it);
            c.insert(a[i].second);
            amount++;
            continue;
        }
        if (c.size() < k) {
            c.insert(a[i].second);
            amount++;
        }
    }
    cout << amount << '\n';
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
