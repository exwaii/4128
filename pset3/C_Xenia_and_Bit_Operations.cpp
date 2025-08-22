#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

int first_bit(int n) {
    int i = 0;
    while (n != 0) {
        n = n >> 1;
        i++;
    }
    return i;
}
void init(vector<int> &tree, int start, int n) {
    if (start >= (1 << n)) {
        return;
    }
    init(tree, 2 * start, n);
    init(tree, 2 * start + 1, n);
    if ((n - first_bit(start)) % 2) {
        tree[start] = (tree[2 * start]) ^ (tree[2 * start + 1]);

    } else {
        tree[start] = (tree[2 * start]) | (tree[2 * start + 1]);
    }
}

void update(vector<int> &tree, int leaf, int value, int n) {
    if (leaf >= (1 << n)) {
        tree[leaf] = value;
    } else {
        if ((n - first_bit(leaf)) % 2) {
            tree[leaf] = (tree[2 * leaf]) ^ (tree[2 * leaf + 1]);

        } else {
            tree[leaf] = (tree[2 * leaf]) | (tree[2 * leaf + 1]);
        }
    }
    if (leaf != 1) {
        update(tree, leaf / 2, value, n);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pi> q(n);

    vector<int> tree(1 << (n + 1), 0);

    for (int i = (1 << n); i < (1 << (n + 1)); i++) {
        cin >> tree[i];
    }

    init(tree, 1, n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        update(tree, (1 << n) + a - 1, b, n);
        cout << tree[1] << '\n';
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
