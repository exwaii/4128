#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool comp(ll a, ll b) {
    return a > b;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].first;
        cin >> s[i].second;  
    }
    sort(s.begin(), s.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; });
    // for (auto i : s) {
    //     cout << i.second << '\n';  
    // }
    vector<ll> h;
    for (auto i : s) {
        h.push_back(i.first);
        push_heap(h.begin(), h.end(), comp);
        // cout << h.size() << '\n';
        if (h.size() > i.second) {
            pop_heap(h.begin(), h.end(), comp);
            h.pop_back();
        }
    }
    ll result = 0;
    for (auto i : h) {
        result += i;
    }
    cout << result << '\n';   
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
