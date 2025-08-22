#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
/*
 * cross product
 */

const double EPS = 1e-8;
typedef pair<double, double> pt;
#define x first
#define y second

pt operator-(pt a, pt b) {
    return pt(a.x - b.x, a.y - b.y);
}

bool zero(double x) {
    return fabs(x) <= EPS;
}

double cross(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

// true if left or straight
// sometimes useful to instead return an int
// -1, 0 or 1: the sign of the cross product
bool ccw(pt a, pt b, pt c) {
    return cross(b - a, c - a) >= -EPS;
}

void solve() {
    int result = 0;
    for (int i = 0; i < 1000; i++) {
        pt a, b, c, o = {0, 0};
        cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
        if (ccw(o, a, b) == ccw(o, b, c)) {
            if (ccw(o, c, a) == ccw(o, a, b)) {
                result++;
            }
        }
    }
    cout << result << '\n';
}

int main() {
    freopen("0102_triangles.txt", "r", stdin);
    // freopen("promote.out", "w", stdout);
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
