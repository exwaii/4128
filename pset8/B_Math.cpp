#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

bool isprime(int x) {
    if (x < 2) return false;
    for (int f = 2; f * f <= x; f++) {
        if (x % f == 0) {
            return false;
        }
    }
    return true;
}
// Returns prime factors in increasing order with right multiplicity.
map<int, int> primefactorize(int x) {
    map<int, int> factors;
    for (int f = 2; f * f <= x; f++) {
        if (isprime(f)) {
            while (x % f == 0) {
                factors[f] += 1;
                x /= f;
            }
        }
    }
    if (x != 1) {
        factors[x] += 1;
    }
    return factors;
}

int bits(int n) {
    int answer = 0;
    while (n > 0) {
        answer++;
        n = n >> 1;
    }
    return answer;
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << ' ' << 0 << '\n';
        return;  
    }
    map<int, int> factors = primefactorize(n);
    // if even already divide by 2
    // if odd + 1 divide by 2
    bool has_odd = false;
    bool is_one = true;
    int answer = 1;
    int max_bits = 1; // when n = 1, max_bits = 1 
    for (auto [factor, count] : factors) {
        max_bits = max(bits(count), max_bits);
        answer *= factor;
    }
    // we need the smallest power of 2 larger or equal to factor count
    // test the power of 2 with same number of bits first
    int power = 1 << (max_bits - 1);

    // check if all equal to a power of 2
    bool x = false;
    bool largest_is_power = true;
    for (auto [factor, count] : factors) {
        cout << factor << count << '\n';
        if (count != power) {
            x = true;
        }
        if (count > power) {
            largest_is_power = false;
        }
    }
    if (!x) {  // they are all magically the same power of 2
        cout << answer << ' ' << max_bits - 1 << '\n';
        return;
    }

    if (largest_is_power) {  // largest factor is already power of 2 but we need to times x
        cout << answer << ' ' << max_bits << '\n';
        return;
    }

    // else we need to go to next power of 2
    cout << answer << ' ' << max_bits + 1 << '\n'; 
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
