#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000 + 5;
static const int LOG  = 18;            

vector<int> adj[MAXN];
int up[LOG+1][MAXN], depthArr[MAXN];
int dsuPar[MAXN];

int findDSU(int x) {
    return dsuPar[x] == x ? x : dsuPar[x] = findDSU(dsuPar[x]);
}
void unionDSU(int a, int b) {
    int ra = findDSU(a), rb = findDSU(b);
    if (ra != rb) {
        dsuPar[rb] = ra;
    }
}

void dfs(int u, int p) {
    up[0][u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        depthArr[v] = depthArr[u] + 1;
        dfs(v, u);
    }
}

void buildLCA(int root, int n) {
    depthArr[root] = 0;
    dfs(root, root);
    for (int k = 1; k <= LOG; ++k) {
        for (int v = 1; v <= n; ++v) {
            up[k][v] = up[k-1][ up[k-1][v] ];
        }
    }
}

int lca(int u, int v) {
    if (depthArr[u] < depthArr[v]) 
        swap(u, v);
    int diff = depthArr[u] - depthArr[v];
    for (int k = 0; k <= LOG; ++k) {
        if (diff & (1 << k)) {
            u = up[k][u];
        }
    }
    if (u == v) return u;
    for (int k = LOG; k >= 0; --k) {
        if (up[k][u] != up[k][v]) {
            u = up[k][u];
            v = up[k][v];
        }
    }
    return up[0][u];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    for (int i = 2, b; i <= N; ++i) {
        cin >> b;
        adj[b].push_back(i);
        adj[i].push_back(b);
    }

    for (int i = 1; i <= N; ++i) {
        dsuPar[i] = i;
    }

    buildLCA(1, N);

    while (Q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            unionDSU(x, y);

        } else if (type == 2) {
            int w = lca(x, y);
            vector<int> path;

            int u = x;
            while (u != w) {
                path.push_back(u);
                u = up[0][u];
            }
            path.push_back(w);

            vector<int> down;
            u = y;
            while (u != w) {
                down.push_back(u);
                u = up[0][u];
            }
            reverse(down.begin(), down.end());

            for (int v : down) 
                path.push_back(v);

            for (int i = 1; i < (int)path.size(); ++i) {
                unionDSU(x, path[i]);
            }

        } else {
            cout << (findDSU(x) == findDSU(y) ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
