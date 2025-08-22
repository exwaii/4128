#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    int d = 0;
    int a[26] = {0};
    for (int i = 0; i < n; i++) { 
        string s = S[i];
        set<int> existing;
        set<int> included;
        for (char c : s) {
            if (a[c - 'a'] != 0) {
                existing.insert(a[c - 'a']);
            }
            included.insert(c - 'a');
        }
        d += 1 - existing.size();
        int first = existing.size() > 0 ? *(existing.begin()) : d;
        for (int i : included) {
            a[i] = first;
        }
    }
    cout << d << '\n'; 
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
