#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int n;
    string s;
    cin >> s;
    map<char, multiset<int>> m;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]].insert(i);
    }
    cin >> n;
    int answer = 0;
    char c;
    int prev = -1, works = 1;
    for (int i = 0; i < 15; i++) {
        cin >> c;
        // if (c == '\n') {
        //     n++;
        //     continue;
        // }
        // if (works == 0) {
        //     continue;
        // }
        // if (c == '\0') {
        //     answer += works;
        //     prev = -1;
        //     works = 1;
        //     if (i == n - 1) {
        //         break;
        //     }
        //     continue;
        // }
        cout << (int) c << ' ';
        // auto it = m.find(c);
        // if (it == m.end()) {
        //     works = 0;
        // }
        // // is there a position in m[c] that is larger than previous?
        // auto next = lower_bound(m[c].begin(), m[c].end(), prev + 1);
        // if (next != m[c].end()) {
        //     prev = *next;
        // } else {
        //     works = 0;
        // }
    }

    cout << answer << '\n';
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
