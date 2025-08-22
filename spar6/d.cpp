#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int w, h;
    cin >> w >> h;
    char m[1001][1001];
    string i;
    pi start;
    for (int i = 0; i < h; i++) {
        cin >> m[i];
        for (int j = 0; j < w; j++) {
            if (m[i][j] == 'S') {
                start = {i, j};
            }
        }
    }
    cin >> i;
    // cout << i.length() << '\n';
    queue<pair<pi, int>> q;
    pair<pi, int> start_time = {start, 0};
    q.emplace(start_time);

    while (!q.empty()) {
        pair<pi, int> current = q.front();
        q.pop();
        int y = current.first.first;
        int x = current.first.second;
        int time = current.second;
        cout << y << ' ' << x << ' ' << time << '\n';
        if (m[y][x] == '#') {
            cout << "nay\n";
            continue;
        }
        if (time == i.length()) {
            m[y][x] = '!';
            cout << "yay\n";
            continue;
        }
        q.push({{y, x - 1}, time + 1});
        if (i[time] == 'N') {
            q.push({{y + 1, x}, time + 1});
        }
        if (i[time] == 'E') {
            q.push({{y, x + 1}, time + 1});
        }
        if (i[time] == 'S') {
            q.push({{y - 1, x}, time + 1});
        }
    }

    for (int i = 0; i < h; i++) {
        cout << m[i] << '\n';
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
