#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

void solve() {
    int x;
    cin >> x;
    if (x % 3) {
        cout << "Toil and trouble.\n";
    } else {
        cout << "Something Wicked!\n";
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
