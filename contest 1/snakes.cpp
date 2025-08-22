#include <bits/stdc++.h>

using namespace std;

void solve() {
    map< char, pair<int, int> > s;
    int n, m;
    cin >> n >> m;
    vector<string> b(n);
    for (int i = n - 1; i >= 0; i--) {
        string c;
        cin >> c;
        if (i % 2) {
            reverse(c.begin(), c.end());
        }
        b[i] = c;
    }
    // for (auto i : b) {
    //     cout << i << '\n'; 
    // }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] != '.') {
                if (s[b[i][j]].first == 0) {
                    s[b[i][j]].first = i * n + j;  
                } else {
                    s[b[i][j]].second = i * n + j;
                    int x = s[b[i][j]].first;
                    int y = s[b[i][j]].second;
                    s[b[i][j]].first = (x + y - abs(x - y))/2;
                    s[b[i][j]].second = (x + y + abs(x - y))/2;
                }
            }
        }
    }
    int pos = 0, r;
    for (int i = 0; i < m; i++) {
        cin >> r;
        pos += r;
        if (pos + 1 >= n * n) {
            pos = n * n - 1;
            break;
        }
        if (b[pos / n][pos % n] != '.') {
            // cout << "omg! " << pos << ' ';
            char c = b[pos / n][pos % n];
            if (c >= 'a') {
                if (pos == s[c].second) {
                    pos = s[c].first;
                }
            } else {
                pos = s[c].second;
            }
        }
        // cout << pos / n << ' ' << pos % n << ' ' << pos + 1 << '\n';
        if (pos + 1 >= n * n) {
            pos = n * n - 1;
            break;
        }
    }
    cout << pos + 1; 
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
