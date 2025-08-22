#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    long long result = 0, curr = 0, a = 0;
    cin >> n;
    cin >> curr;
    for (int i = 1; i < n; i++) {
        // if curr and a diff sign, add curr to result, new curr is a
        // if same sign take largest
        cin >> a;
        if ((curr < 0) == (a < 0)) {
            curr = curr > a ? curr : a;   
        } else {
            result += curr;
            curr = a;
        }
    }
    result += curr;
    cout << result << '\n'; 
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
