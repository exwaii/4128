#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

const int MOD = 998244353;

const int N = 31700;

int is_prime[N + 1];  // least prime factor
vector<int> primes;

void sieve(void) {
    for (int i = 0; i <= N; i++) {
        is_prime[i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        // cout << i << '\n';
        if (is_prime[i] == 1) {  // prime
            for (int j = 2 * i; j <= N; j += i) {
                // first prime factor is also smallest
                is_prime[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

vector<int> p_factorisation(int x) {
    vector<int> factors;
    for (int p : primes) {
        if (x % p == 0) {
            factors.push_back(p);
            x /= p;
        }
        while (x % p == 0) {
            x /= p;
        }
        if (x == 1) {
            return factors;
        }
    }
    factors.push_back(x);
    return factors;
}

ll count_multiples(vector<int> &p, int g, int m) {  // count multiples of g coprime to p
    ll sum = 0;
    for (int msk = 1; msk < (1 << p.size()); ++msk) {
        ll mult = 1,
            bits = 0;
        for (int i = 0; i < (int)p.size(); ++i)
            if (msk & (1 << i)) {
                ++bits;
                mult *= p[i];
            }

        ll cur = m / mult;
        cur /= g;
        if (bits % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }

    return m / g - sum;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] % a[i]) {
            cout << 0 << '\n';
            return;
        }
    }

    ll result = 1;

    for (int i = 1; i < n; i++) {
        vector<int> exclude = p_factorisation(a[i - 1] / a[i]);
        result *= count_multiples(exclude, a[i], m);
        result %= MOD;
    }
    cout << result << '\n';
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    sieve();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
