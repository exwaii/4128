#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

const int N = 100100;
// the number of additional nodes created can be as high as the next power of two up from N (2^17 = 131,072)

// actual length of underlying array
// query the sum over [qL, qR) (0-based)
// i is the index in the tree , rooted at 1 so children are 2i and 2i+1
// instead of explicitly storing each node's range of responsibility [cL,cR), we
// calculate it on the way down
// the root node is responsible for [0, n)
struct node {
    ll sum;
    int m;
    int rval;
    int lval;
    bool increasing;
    bool decreasing;
};
vector<node> tree;
int n;
node merge(const node &l, const node &r) {
    node res;
    res.m = max(l.m, r.m);
    res.sum = l.sum + r.sum;
    res.rval = r.rval;
    res.lval = l.lval;
    res.increasing = l.increasing && r.increasing && (l.rval <= r.lval);
    res.decreasing = l.decreasing && r.decreasing && (l.rval >= r.lval);
    return res;
}

node query(int qL, int qR, int i = 1, int cL = 0, int cR = n) {
    // the query range exactly matches this node's range of responsibility
    if (cL == qL && cR == qR)
        return tree[i];
    // we might need to query one or both of the children
    int mid = (cL + cR) / 2;

    if (qR <= mid) return query(qL, qR, i * 2, cL, mid);
    if (qL >= mid) return query(qL, qR, i * 2 + 1, mid, cR);
    // query the part within the left child [cL, mid), if any
    return merge(query(qL, mid, i * 2, cL, mid), query(mid, qR, i * 2 + 1, mid, cR));
}

void init(int i, int cL, int cR, vector<int> &a) {
    if (cR - cL == 1) {
        node res{a[cL], a[cL], a[cL], a[cL], true, true};
        tree[i] = res;
        return;
    }
    int mid = (cR + cL) / 2;
    init(i * 2, cL, mid, a);
    init(i * 2 + 1, mid, cR, a);
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}

void update(int p, int v, int i = 1, int cL = 0, int cR = n) {
    if (cR - cL == 1) {
        tree[i] = node{v, v, v, v, true, true};
        return;
    }
    // figure out which child is responsible for the index (p) being updated
    int mid = (cL + cR) / 2;
    if (p < mid)
        update(p, v, i * 2, cL, mid);
    else
        update(p, v, i * 2 + 1, mid, cR);
    // once we have updated the correct child , recalculate our stored value.
    tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
}

void solve() {
    int m;
    cin >> n >> m;

    tree.resize(4 * n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    init(1, 0, n, a);

    char o;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> o >> x >> y;
        if (o == 'U') {
            update(x - 1, y);
        } else {
            node ans = query(x - 1, y);
            if (o == 'M') {
                cout << ans.m;
            } else if (o == 'S') {
                cout << ans.sum;
            } else if (o == 'I') {
                cout << ans.increasing;
            } else if (o == 'D') {
                cout << ans.decreasing;
            }
            cout << '\n';
        }
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
