#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>

struct edge {
    int u, v, w;
};
bool operator<(const edge& a, const edge& b) { return a.w < b.w; }

const int MAXN = 100'000 + 1;
edge edges[MAXN];
int parent[MAXN];
int sz[MAXN];

void make_set(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;  
        sz[i] = 1;      
    }
}

int root(int u) {
    if (parent[u] != u)
        parent[u] = root(parent[u]); 
    return parent[u];
}

void join(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;  

    if (sz[u] < sz[v])  
        swap(u, v);

    parent[v] = u;  
    sz[u] += sz[v];  
}

// long long kruskal(int m) {
//     sort(edges, edges + m);  // sort by increasing weight
//     long long total_weight = 0;
//     for (int i = 0; i < m; i++) {
//         edge& e = edges[i];
//         // if the endpoints are in different trees , join them
//         if (root(e.u) != root(e.v)) {
//             total_weight += e.w;
//             join(e.u, e.v);
//         }
//     }
//     return total_weight;
// }

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        edge curr;
        cin >> curr.u >> curr.v >> curr.w;  
        edges[i] = curr;
    }
    
    sort(edges, edges + m);  // sort by increasing weight
    make_set(n);

    long long total_weight = 0;
    long long heaviest_edge = 0;
    for (int i = 0; i < m; i++) {
        edge& e = edges[i];
        if (root(e.u) != root(e.v)) {
            total_weight += e.w;
            if (e.w > heaviest_edge) {
                heaviest_edge = e.w;
            }
            join(e.u, e.v);
        }
    }
    cout << total_weight - heaviest_edge << '\n';
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
