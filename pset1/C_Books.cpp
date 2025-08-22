#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long t;
    cin >> n >> t;
    vector<int> a(n+1);  // cumulative
    a[0] = 0;
    int curr = 0;
    for (int i = 1; i < n+1; i++) {
        cin >> a[i];
        a[i] += curr;
        curr = a[i];
    }
    
    // iterate through, bsearch for when it ends (nlogn)
    // a[i] is the number of time it takes to read 1 to i
    // a[i] - a[j] is the time it takes to read j+1 to i (whcih is i-j books)
    // for each i we want to find the largest a[j] s.t a[j] - a[i] < t
    // -> first a[j] such that a[j] < a[i] + t 
    int result = 0;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a.begin() + i, a.end(), t + a[i]);
        if (--it != a.begin() + i) {
            int books = int(it - a.begin() - i); 
            result = books > result ? books : result;    
        }
    }
    cout << result << "\n";
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
