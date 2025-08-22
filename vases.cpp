#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, a, b, c;
    cin >> N; 
    if (N < 6) {
        a = 0;
        b = 0;
        c = 0;
    } else {
        a = 1;
        b = 2; 
        c = N - 3;
    }
    cout << a << ' ' << b << ' ' << c << '\n';    
}

int main() {
    int tc = 1;
    // cin >> tc;3
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
