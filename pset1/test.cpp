#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; 
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i]; 
    }
    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
        int target = p[i], curr = 0;
        for (int j = 0; i < n; i++) {
            curr += abs(target - p[i]);
        }
        if (curr < result) {
            result = curr;
        }
    }
    cout << result; 
}

int main() {
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
