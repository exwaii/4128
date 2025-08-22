#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> edge;  // (distance , vertex)
#define ll long long
#define pi pair<int, int>

// int parent[500000];
// int subtree_size[500000];
vector<int> parent, subtree_size;

void init(int n) {
    parent.assign(n, 0);
    subtree_size.assign(n, 1);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        // subtree_size[i] = 1;
    }
}

int root(int x) {
    // only roots are their own parents
    return parent[x] == x ? x : root(parent[x]);
}

bool join(int x, int y) {
    // join roots
    x = root(x);
    y = root(y);
    // test whether already connected
    if (x == y)
        return false;
    // size heuristic
    // hang smaller subtree under root of larger subtree
    if (subtree_size[x] < subtree_size[y]) {
        parent[x] = y;
        subtree_size[y] += subtree_size[x];
    } else {
        parent[y] = x;
        subtree_size[x] += subtree_size[y];
    }
    return true;
}

struct query {
    char q;
    int a;
    ll prev;
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    // n, m, q < 5*10^5
    // o(qlogm)
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<edge> r(m);
    for (int i = 0; i < m; i++) {
        cin >> r[i].first >> r[i].second;
        --r[i].first;
        --r[i].second;
    }

    vector<ll> ans(q);
    vector<query> queries(q);
    set<int> broken;

    for (int i = 0; i < q; i++) {
        cin >> queries[i].q;
        cin >> queries[i].a;
        --queries[i].a;
        if (queries[i].q == 'P') {
            queries[i].prev = p[queries[i].a];
            cin >> p[queries[i].a];
        } else {
            broken.insert(queries[i].a);
        }
    }

    multiset<ll> largest(p.begin(), p.end());
    vector<ll> populations(n);
    init(n);

    for (int i = 0; i < n; i++) {
        populations[i] = p[i];
    }
    for (int i = 0; i < m; i++) {
        if (broken.find(i) == broken.end()) {
            int town1 = r[i].first, town2 = r[i].second;

            ll old1 = populations[root(town1)], old2 = populations[root(town2)];

            if (!join(r[i].first, r[i].second)) {
                continue;
            }
            populations[root(town1)] = old1 + old2;
            largest.erase(largest.find(old1));
            largest.erase(largest.find(old2));
            largest.insert(old1 + old2);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        ans[i] = *largest.rbegin();
        query curr = queries[i];
        if (curr.q == 'P') {
            ll delta = p[curr.a];  // change new - old
            delta -= curr.prev;
            p[curr.a] = curr.prev;
            largest.erase(largest.find(populations[root(curr.a)]));
            populations[root(curr.a)] -= delta;
            largest.insert(populations[root(curr.a)]);
        } else {
            int idx = curr.a;
            int town1 = r[idx].first, town2 = r[idx].second;

            ll old1 = populations[root(town1)], old2 = populations[root(town2)];

            if (!join(r[idx].first, r[idx].second)) {
                continue;
            }
            populations[root(town1)] = old1 + old2;
            largest.insert(old1 + old2);
            largest.erase(largest.find(old1));
            largest.erase(largest.find(old2));
        }
    }
    for (auto i : ans) {
        cout << i << '\n';
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
