#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; 
    cin >> n;
    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    long long target = p[n/2];
    long long result = 0;
    for (long long i : p) {
        result += abs(target - i);
    } 
    cout << result; 
}

int main() {
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
