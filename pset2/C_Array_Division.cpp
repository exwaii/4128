#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2) {
        cout << "NO\n";
        return;
    }
    long long target = sum / 2;
    set<long long> seen;
    sum = 0;
    for (int i : a) {
        sum += i;
        if (sum == target) {
            cout << "YES\n";
            return;
        }
        seen.insert(i);
        if (seen.find(sum - target) != seen.end()) {
            cout << "YES\n";
            return; 
        }
    }
    seen.clear();
    sum = 0;
    for (int j = n-1; j >= 0; j--) {
        int i = a[j];
        sum += i;
        if (sum == target) {
            cout << "YES\n";
            return;
        }
        seen.insert(i);
        if (seen.find(sum - target) != seen.end()) {
            cout << "YES\n";
            return; 
        }
    }
    cout << "NO\n";
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
