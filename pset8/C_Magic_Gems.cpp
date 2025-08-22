#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

const ll MOD = 1000000007;

vector<vector<ll>> one(ll size) {
    vector<vector<ll>> res(size, vector<ll>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = (i == j);
        }
    }
    return res;
}
void mmul(const vector<vector<ll>> &a, const vector<vector<ll>> &b, vector<vector<ll>> &res, ll size) {
    for (int i = 0; i < size; i++) {  // ith row, jth column ->
        for (int j = 0; j < size; j++) {
            res[i][j] = 0;
            for (int k = 0; k < size; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
        }
    }
}

vector<vector<ll>> m_pow(const vector<vector<ll>> &x, ll n, ll size) {
    if (n == 0) {
        return one(size);
    }
    vector<vector<ll>> b = m_pow(x, n / 2, size);
    vector<vector<ll>> square(size, vector<ll>(size));
    mmul(b, b, square, size);
    vector<vector<ll>> res(size, vector<ll>(size));
    if (n % 2 == 1) {
        mmul(square, x, res, size);
    } else {
        return square;
    }
    return res;
}

ll ans(const vector<vector<ll>> &a, ll size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res += a[size - 1][i];
    }
    return res % MOD;
}

// let M_x denote number of ways for m = M and n = x
// M_x = 1 where x < m
// M_x = 1 (all 1s) + ()()

void solve() {
    ll n, m;
    cin >> n >> m;
    // recurrence is M_x = M_(x-1) + M_(x-m)
    // corresponds to multiply (1, 1,.. 1) by the matrix
    // 0 1 0 0 .... 0
    // 0 0 1 0 .... 0
    // 0 0 0 1 .... 0
    // ...
    // 1 0 0 0 .... 1
    // n times
    // we will fast exponentiate
    // how to fast exponentiate matrices? m log n is fine right
    if (n < m) {
        cout << 1 << '\n';
        return;
    }
    vector<vector<ll>> x(m, vector<ll>(m));
    for (int i = 0; i < m - 1; i++) {
        x[i][i + 1] = 1;
    }
    x[m - 1][0] = 1;
    x[m - 1][m - 1] = 1;
    vector<vector<ll>> ans_m = m_pow(x, n - m + 1, m);
    ll res = ans(ans_m, m);
    cout << res << '\n';
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
