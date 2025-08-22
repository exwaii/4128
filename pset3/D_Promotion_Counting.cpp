#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pi pair<int, int>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void merge(int a, int b, vector<ordered_map> &suboordinates) {  // put b into a
    if (suboordinates[a].size() < suboordinates[b].size()) suboordinates[a].swap(suboordinates[b]);
    for (int x : suboordinates[b]) {
        suboordinates[a].insert(x);
    }
}

void dfs(int n, vector<vector<int>> &adj, vector<int> &p, vector<int> &ans, vector<ordered_map> &subordinates) {
    // dfs on children
    for (int child : adj[n]) {
        dfs(child, adj, p, ans, subordinates);  // assume ans has been computed for children
        merge(n, child, subordinates);
    }
    ans[n] = subordinates[n].size() - subordinates[n].order_of_key(p[n]);
    subordinates[n].insert(p[n]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<vector<int>> adj(n);
    vector<ordered_map> subordinates(n);
    vector<int> ans(n);
    int parent;
    for (int i = 1; i < n; i++) {
        cin >> parent;
        parent--;
        adj[parent].push_back(i);
    }
    dfs(0, adj, p, ans, subordinates);
    for (int x : ans) {
        cout << x << '\n'; 
    }
}

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
