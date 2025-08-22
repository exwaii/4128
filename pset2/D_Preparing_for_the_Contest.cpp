#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

struct Student {
    int ability;
    int cost;
    int idx;
};

void solve() {
    int n, m;
    ll s;
    cin >> n >> m >> s;
    vector<pi> bugs(m);
    vector<Student> students(n);

    for (int i = 0; i < m; i++) {
        cin >> bugs[i].first;
        bugs[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> students[i].ability;
        students[i].idx = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> students[i].cost;
    }
    sort(bugs.begin(), bugs.end(), [](pi a, pi b) { return a.first > b.first; });
    sort(students.begin(), students.end(), [](Student a, Student b) { return a.ability > b.ability; });
    if (bugs[0].first > students[0].ability) {
        cout << "NO\n";
        return;
    }
    // number of days max is number of bugs
    // min 1 i guess
    // need n log n or n log n log n (10^5)

    // for each day,
    // we want the cheapest student for each bug
    // for d days,
    // we want the d hardest problems done by the same person
    // and so on (induction proof, person who does hardest can also do d hardest)

    int left = 1, right = m + 1, d;
    // if d can be done, right = d, left stays
    // if d cannot be done, left = d+1, right stays.
    // when there are two days, we want to test the left first
    while (left < right) {
        bool pass = true;
        d = (left + right) / 2;
        int hardest, pointer = 0;
        ll cost = 0;
        priority_queue<pi, vector<pi>, greater<pi>> labor;
        for (int i = 0; i < m; i += d) {
            hardest = bugs[i].first;
            while (pointer < n && students[pointer].ability >= hardest) {
                labor.emplace(students[pointer].cost, students[pointer].idx);
                pointer++;
            }
            if (labor.empty()) {
                pass = false;
                break;
            }
            cost += labor.top().first;
            labor.pop();
            if (cost > s) {
                pass = false;
                break;
            }
        }
        if (pass) {
            right = d;
        } else {
            left = d + 1;
        }
    }
    if (left == m + 1) {
        cout << "NO\n";
        return;
    }
    d = left;
    int pointer = 0;
    ll cost = 0;
    vector<int> ans(m);
    priority_queue<pi, vector<pi>, greater<pi>> labor;
    for (int i = 0; i < m; i += d) {
        int hardest = bugs[i].first;
        while (pointer < n && students[pointer].ability >= hardest) {
            labor.emplace(students[pointer].cost, students[pointer].idx);
            pointer++;
        }   
        if (labor.empty()) {
            cout << "NO\n";
            return;
        }
        cost += labor.top().first;
        for (int j = i; j < min(m, i + d); j++) {
            ans[bugs[j].second] = labor.top().second;
        }
        labor.pop();
        if (cost > s) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        if (i) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
