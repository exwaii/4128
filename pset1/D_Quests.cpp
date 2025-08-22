#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> a(n + 1);  // a[n] is max coins earnable in n days without repeating. a[0] = 0, a[1] = max(a_i) etc.
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), [](int a, int b) { return a > b; });
    for (int i = 2; i <= n; i++) {
        a[i] += a[i - 1];
    }
    
    if (a[1] * d < c) {  // max coins earnable in d days (with repeating) is just d * max(a_i)
        cout << "Impossible\n";
        return;
    }

    if (a[n > d ? d : n] >= c) {  // its infinite if we get all the coins without repeating any quests. (we are bounded by d or n)
        cout << "Infinity\n";
        return;
    }

    ll left = 0, right = d - 1, mid;
    while (left < right) {
        mid = (left + right + 1) / 2;                                                                           // number of days (mid is our candidate for k)
        if ((d / (mid + 1)) * (a[mid + 1 > n ? n : mid + 1]) + a[d % (mid + 1) > n ? n : d % (mid + 1)] < c) {  // not possible in mid or more days
            right = mid - 1;
        } else {  // possible in mid days or more, need to go to mid;
            left = mid;
        }
    }
    cout << left << '\n';
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
