#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>


const int N = 10000001;
int lp[N + 1];  // least prime factor

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void sieve(void) {
    for (int i = 2; i <= N; i++) {
        lp[i] = i;
    }
    for (int i = 2; i * i <= N; i++) {
        if (lp[i] == i) {  // prime
            for (int j = i * i; j <= N; j += i) {
                // first prime factor is also smallest
                if (lp[j] == j) {
                    lp[j] = i;
                }
            }
        }
    }
}

set<int> p_factorisation(int x) {
    // int x = og;
    // if (lp[x] == x) {
    //     // cout << x << '\n';
    //     return ;
    // }
    set<int> factors;
    while (x > 1) {
        int curr = lp[x];
        factors.insert(curr);
        while (x % curr == 0) {
            x /= curr;
        }
    }
    // cout << "factors of: " << x << '\n';
    // for (auto i : factors) {
    //     cout << i << '\n';
    // }
    return factors;
}

pi divisors(int a) {
    set<int> factors = p_factorisation(a);
    if (factors.size() < 2) return {-1, -1};
    auto it = factors.begin();
    int d1 = *(it++);
    int d2 = 1;
    for (; it != factors.end(); it++) {
        d2 *= *it;
    }
    return {d1, d2};
}
// 5*10^5 times each prime max log 10^7 factors and we do it cubed?
// log 10^7 is 23?
// sieve for all primes?
// if primes or a multiple of a prime, kill?
void solve() {
    int n;
    cin >> n;
    vector<ll> first(n);
    vector<ll> second(n);
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pi ans = divisors(a);
        first[i] = ans.first;
        second[i] = ans.second;
    }
    for (int i = 0; i < n; i++) {
        cout << first[i];
        if (i != n - 1) {
            cout << ' ';
        }
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << second[i];
        if (i != n - 1) {
            cout << ' ';
        }
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int tc = 1;
    // cin >> tc;
    sieve();

    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}


// for 9693832

// 17 2 2 103 2
// 19 307 23 16567 3


// 17 2 2 103 2
// 19 3947 8059 16567 3
