/*
 *
 * code for shortestpaths
 *
 */

/*
 * dijkstra
 */

#include <queue>
using namespace std;

typedef pair<int, int> edge; // (distance, vertex)

const int INF = 1000*1000*1000+7; // more than any real distance
const int N = 100100;
vector<edge> edges[N]; // assume prefilled adjlist
int dist[N]; // dist[i] = INF denotes unseen

void dijkstra (int s) {
  fill(dist, dist+N, INF);
  priority_queue<edge, vector<edge>, greater<edge>> pq;
  pq.emplace(0, s); // distance to s itself is zero
  while (!pq.empty()) {
    // choose (d, v) so that d is minimal
    // i.e. the closest unvisited vertex
    edge cur = pq.top();
    pq.pop();
    int v = cur.second, d = cur.first;
    if (dist[v] == INF) { // if not seen
      dist[v] = d;
      for (edge nxt : edges[v]) { // relax all edges from v
        int u = nxt.second, w = nxt.first;
        if (dist[u] == INF) { pq.emplace(d + w, u); }
      }
    }
  }
}

/*
 * bellman ford relax
 */

struct edge {
  int u, v, w; // u -> v of weight w
  edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<int> dist(n);
vector<edge> edges;

// global relaxation: try to relax every edge in the graph
// returns whether any distance was updated
bool relax() {
  bool relaxed = false;
  for (edge e : edges) {
    // we don't want to relax an edge from an unreachable vertex
    if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
      relaxed = true;
      dist[e.v] = dist[e.u] + e.w;
    }
  }
  return relaxed;
}

/*
 * bellman ford main
 */

// Puts distances from source vertex 0 in dist
// Returns true if there is a negative cycle, false otherwise.
// NOTE: You can't trust the dist array if this function returns True.
bool bellman_ford() {
  fill(dist.begin(), dist.end(), INF);
  dist[0] = 0;
  // V-1 global relaxations
  // if no updates are made in an entire round, we can early exit
  // SPFA optimises this further
  for (int i = 0; i < n - 1; i++) {
    if (!relax()) { break; }
  }
  // there is a negative cycle iff any edge can be relaxed further
  // therefore try a Vth global relaxation
  // true if any changes made, false otherwise
  // can micro-optimise by early exiting when the first change is made
  return relax();
}

/*
 * floyd warshall
 */

// the distance between everything is infinity
for (int u = 0; u < n; ++u)
  for (int v = 0; v < n; ++v) { dist[u][v] = INF; }

// update the distances for every directed edge
// each edge u -> v with weight w
for (edge e : edges) { dist[e.u][e.v] = e.w; }

// every vertex can reach itself
for (int u = 0; u < n; ++u) { dist[u][u] = 0; }

for (int i = 0; i < n; i++)
  for (int u = 0; u < n; u++)
    for (int v = 0; v < n; v++) {
      // dist[u][v] is the length of the shortest path from u to v using only 0 to i as intermediate vertices
      // now that we're allowed to also use i, the only new path that could be shorter is u -> i -> v
      dist[u][v] = min(dist[u][v], dist[u][i] + dist[i][v]);
    }

/*
 * two buttons
 */

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int MAXVAL=20*1000*1000+5;
const int INF = 1000*1000*1000+7;
int n, m, v[MAXVAL];
queue<int> q;

int main () {
  cin >> n >> m;
  fill(v, v + MAXVAL, INF);
  q.push(n);
  v[n] = 0;
  while (!q.empty()) {
    int i = q.front(); q.pop();
    if (i-1 > 0 && v[i] + 1 < v[i-1]) {
      v[i-1] = v[i] + 1;
      q.push(i - 1);
    }
    if (i*2 < MAXVAL && v[i] + 1 < v[i*2]) {
      v[i*2] = v[i] + 1;
      q.push(i * 2);
    }
  }
  cout << v[m] << '\n';
}

/*
 * climbing 1
 */

struct state {
  int pid[3];
  int dist;
};

bool operator< (const state &a, const state &b) {
  // reversing the comparison makes pq a min heap by default
  return a.dist > b.dist;
}

priority_queue<state> pq;
pq.push(begin);
bool running = true;
while (!pq.empty() && running) {
  state cur = pq.top();
  pq.pop();
  // check if done
  for (int j = 0; j < 3; j++) {
    if (cur.pid[j] == n) {
      running = false;
      break;
    }
    // to be continued

/*
 * climbing 2
 */

    // try disengaging our jth hold
    for (int j = 0; j < 3; j++) {
      // and moving to hold number i
      for (int i = 1; i <= n; i++) {
        // can't reuse existing holds
        if (i == cur.pid[0] || i == cur.pid[1] || i == cur.pid[2]) { continue; }

        state tmp = cur;
        tmp.dist += dist(cur.pid[j], i);
        tmp.pid[j] = i;
        sort(tmp.pid, tmp.pid + 3);

        // try to move if valid
        if (valid(tmp) &&
            (!seen[tmp.pid[0]][tmp.pid[1]][tmp.pid[2]] ||
             seen[tmp.pid[0]][tmp.pid[1]][tmp.pid[2]] > tmp.dist)) {
          pq.push(tmp);
          seen[tmp.pid[0]][tmp.pid[1]][tmp.pid[2]] = tmp.dist;
        }
      }
    } 
  }
}

/*
 * intercountry 1
 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, long long> edge;

const int MAXN = 100100, MAXC = 100100;
int N, C, A, B;
vector<edge> edges[MAXN+2*MAXC]; // (dest, dist)

// city nodes are at 1..N
inline int city (int i) { return i; }
// "outgoing" country nodes are at N+1..N+C
inline int dep (int j) { return N + j; }
// "incoming" country nodes are at N+C+1..N+C+C
inline int arr (int j) { return N + C + j; }

// need bigger INF than usual, about 1e15
long long dist[MAXN+2*MAXC];
void dijkstra (int s);

/*
 * intercountry 2
 */

int main(void) {
    cin >> N >> C >> A >> B;
    for (int i = 1; i <= N; i++) { // cities
        int j; cin >> j; // country
        // can go to your country's "intercountry departures" for free
        edges[city(i)].emplace_back(dep(j), 0);
        // can come from your country's "intercountry arrivals" for free
        edges[arr(j)].emplace_back(city(i), 0);
    }
    for (int i = 0; i < A; i++) { // intercity flights
        int a, b; long long w; 
        cin >> a >> b >> w;
        edges[city(a)].emplace_back(city(b), w);
    }
    for (int i = 0; i < B; i++) { // intercountry flights
        int a, b; long long w; 
        cin >> a >> b >> w;
        edges[dep(a)].emplace_back(arr(b), w);
    }
    dijkstra(city(1));
    cout << dist[city(n)] << '\n';
}

/*
 * escape 1
 */

// up down left right in a grid
const int di[4] = { -1, 1, 0, 0 };
const int dj[4] = { 0, 0, -1, 1 };  

vector<pair<int,int>> enemies; // assume filled in
// search from all enemy safe houses to find
// each square's minimum distance to an enemy safe house
queue<pair<int, int>> q;
for (auto enemy : enemies) {
  q.push(enemy);
  dist_to_enemy[enemy.first][enemy.second] = 0;
}

while (!q.empty()) {
  pair<int, int> cur = q.front(); q.pop();
  int i = cur.first, j = cur.second;
  for (int d = 0; d < 4; d++) { // try all neighbours
    int ni = i + di[d], nj = j + dj[d];
    // if off board, ignore
    if (ni < 0 || ni >= N || nj < 0 || nj >= M) { continue; }
    // if seen, ignore
    if (dist_to_enemy[ni][nj] != INF) { continue; }
    dist_to_enemy[ni][nj] = dist_to_enemy[i][j] + 1;
    q.emplace(ni, nj);
  }
}

/*
 * escape 2
 */

// binary search // answer in (lo, hi]
int lo = -1, hi = min(dist_to_enemy[i1][j1], dist_to_enemy[i2][j2]), sol = -1;  
while (lo != hi) {
  int X = (lo + hi + 1) / 2;
  // BFS, since the edges are unit weight
  vector<vector<int>> dist(N, vector<int>(M, INF));
  dist[i1][j1] = 0;
  q.emplace(i1, j1);

  while (!q.empty()) {
    int i = q.front().first, j = q.front().second; q.pop();
    for (int d = 0; d < 4; ++d) {
      int ni = i + di[d], nj = j + dj[d];
      if (ni < 0 || ni >= N || nj < 0 || nj >= M) { continue; }
      if (dist_to_enemy[ni][nj] < X) { continue; }
      if (dist[ni][nj] != INF) { continue; }
      dist[ni][nj] = dist[i][j] + 1;
      q.emplace(ni, nj);
    }
  }

  if (dist[i2][j2] == -1) {
    hi = X - 1;
  } else {
    lo = X;
    sol = dist[i2][j2];
  }
}

/*
 * second shortest 1
 */

typedef tuple<int, int, int> state; // dist, vertex, previous
typedef pair<int, int> edge; // dist, vertex
vector<edge> adj[N]; // dist, dest
vector<edge> adj_r[N]; // dist, origin

// dist1[u] = shortest distance from s to u
vector<int> dist1(n+1, INF), pred(n+1);
priority_queue<state, vector<state>, greater<state>> pq;
pq.emplace(0, s, 0);
while (!pq.empty()) {
  state cur = pq.top(); pq.pop();
  int d = get<0>(cur), v = get<1>(cur), u = get<2>(cur);
  if (dist1[v] == INF) {
    dist1[v] = d;
    pred[v] = u;
    for (edge nxt : adj[v]) {
      int l = nxt.first, w = nxt.second; // v -> w of weight l
      if (dist1[w] != INF) { pq.emplace(d+l, w, v); }
    }
  }
}

// to be continued

/*
 * second shortest 2
 */

// dist2[u] = shortest distance from u to t
vector<int> dist2(n+1, INF);
priority_queue<state, vector<state>, greater<state>> pq_r;
pq_r.emplace(0, t, 0);
while (!pq_r.empty()) {
  state cur = pq_r.top(); pq_r.pop();
  int d = get<0>(cur), v = get<1>(cur); // don't need prev
  if (dist2[v] == INF) {
    dist2[v] = d;
    for (edge nxt : adj_r[v]) { // reverse graph
      int l = nxt.first, w = nxt.second; // v -> w of weight l
      if (dist2[w] != INF) { pq_r.emplace(d+l, w, v); }
    }
  }
}

int res = INF;
int u = t, v = 0; // special case for diverging at the end
while (u != 0) { // u -> v is an edge in the shortest walk
  for (edge e : adj[u]) { // try this edge instead of it
    int l = e.first, w = e.second;
    if (w != v) { res = min(res, dist1[u] + l + dist2[v]); }
  }
  v = u;
  u = pred[u];
}

