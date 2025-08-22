/*
 *
 * code for comp geom
 *
 */

/*
 * double comparison
 */

const double EPS = 1e-8;

bool zero(double x) {
  return fabs(x) <= EPS;
}


/*
 * cross product
 */

const double EPS = 1e-8;
typedef pair<double, double> pt;
#define x first
#define y second

pt operator+(pt a, pt b) {
  return pt(a.x + b.x, a.y + b.y);
}

pt operator-(pt a, pt b) {
  return pt(a.x - b.x, a.y - b.y);
}

bool zero(double x) {
  return fabs(x) <= EPS;
}

double cross(pt a, pt b) {
  return a.x*b.y - a.y*b.x;
}

// true if left or straight
// sometimes useful to instead return an int
// -1, 0 or 1: the sign of the cross product
bool ccw(pt a, pt b, pt c) {
  return cross(b - a, c - a) >= -EPS;
}

/*
 * segment segment intersection
 */

typedef pair<pt, pt> seg;

bool collinear(seg ab, seg cd) { // all four points collinear
  pt a = ab.first, b = ab.second, c = cd.first, d = cd.second;
  return zero(cross(b - a, c - a)) &&
         zero(cross(b - a, d - a));
}

inline double sq(double t) { return t * t; }

double dist(pt p, pt q) { return sqrt(sq(p.x - q.x) + sq(p.y - q.y)); }

bool intersect(seg ab, seg cd) {
  pt a = ab.first, b = ab.second, c = cd.first, d = cd.second;
  
  if (collinear(ab, cd)) {
    double maxDist = max({dist(a, b), dist(a, c), dist(a, d),
                          dist(b, c), dist(b, d), dist(c, d)});
    return maxDist < dist(a, b) + dist(c, d) + EPS;
  }

  // only finds proper intersections
  // for non-proper, have ccw return an int
  // then return whether both products of ccws are <= 0
  return ccw(a, b, c) != ccw(a, b, d) &&
         ccw(c, d, a) != ccw(c, d, b);
}

/*
 * polygon area trapezoidal
 */

double area(vector<pt> pts) {
  double res = 0;
  int n = pts.size();
  for (int i = 0; i < n; i++) {
    //     (a        + b             ) * h/2 (/2 moved to the end)
    res += (pts[i].y + pts[(i+1)%n].y) * (pts[(i+1)%n].x - pts[i].x);
    // sometimes, h will be negative, which means we subtract area
  }
  return res/2.0;
}

/*
 * polygon area cross product
 */

double area(vector<pt> pts) {
  double res = 0;
  int n = pts.size();
  for (int i = 1; i < n-1; i++) {
    // i = 0 and i = n-1 are degenerate triangles, OK to omit
    // e.g. if i = 1 is ABC, and i = 2 is ACD, then i = 0 is AAB
    res += cross(pts[i] - pts[0], pts[i+1] - pts[0]);
  }
  return res/2.0;
}

/*
 * polygon area 1
 */

pt operator-(pt p, pt q) {
  return (pt){p.x - q.x, p.y - q.y};
}

pt operator+(pt p, pt q) {
  return (pt){p.x + q.x, p.y + q.y};
}

pt rotate(pt p, double a) {
  pt res;
  res.x = p.x * cos(a) - p.y * sin(a);
  res.y = p.x * sin(a) + p.y * cos(a);
  return res;
}

pt rotate(pt p, double a, pt o) {
  return rotate(p - o, a) + o;
}

// this is pi/2 - atan2(a.y - b.y, a.x - b.x);
double theta = atan2(a.x - b.x, a.y - b.y);
a = rotate(a, theta, b);
for (int i = 0; i < n; i++) {
  pts[i] = rotate(pts[i], theta, b);
}

/*
 * polygon area 2
 */

double res = 0;
for (int i = 0; i < n; i++) {
  pt p = pts[i];
  pt q = pts[(i+1)%n];

  int sign = 1;
  if (p.x > q.x) {
    sign *= -1;
    swap(p, q);
  }
  
  // vertical or almost vertical means no area
  if (fabs(q.x - p.x) < 1e-9) { continue; }
  
  double m = (q.y - p.y) / (q.x - p.x);
  double c = p.y - m*p.x;
  
  // the rectangle cuts out the bit from nx to mx
  double nx = max(p.x, min(q.x, a.x - w));
  double ny = m*nx + c;
  double mx = min(q.x, max(p.x, a.x + w));
  double my = m*mx + c;
  
  // find the areas of the at most two pieces that aren't cut out
  res += sign * abs(nx - p.x) * (ny + p.y) / 2;
  res += sign * abs(q.x - mx) * (my + q.y) / 2;
}

/*
 * convex hull
 */

vector<pt> half_hull(vector<pt> pts) {
  vector<pt> res;
  for (int i = 0; i < pts.size(); i++) {
    // ccw means we have a left turn; we don't want that
    while (res.size() >= 2 &&
           ccw(res[res.size()-2], res[res.size()-1], pts[i])) {
      res.pop_back();
    }
    res.push_back(pts[i]);
  }
  return res;
}

vector<pt> convex_hull(vector<pt> pts) {
  sort(pts.begin(), pts.end());
  vector<pt> top = half_hull(pts);

  reverse(pts.begin(), pts.end());
  vector<pt> bottom = half_hull(pts);
  
  // remove repeated endpoints
  top.pop_back(); bottom.pop_back();
  vector<pt> res(top.begin(), top.end());
  res.insert(res.end(), bottom.begin(), bottom.end());
  return res;
}

/*
 * half plane intersection primitives
 */

typedef pair<double, double> pt;

struct line {
  double a, b, c;
};

struct half_plane {
  line l;
  bool neg; // is the inequality <= or >=
};

pt intersect(line f, line g) {
  double d = f.a*g.b - f.b*g.a;
  double y = (f.a*g.c - f.c*g.a)/(f.b*g.a - f.a*g.b);
  double x = (f.c*g.b - f.b*g.c)/(f.b*g.a - f.a*g.b);
  return pt(x, y);
}

bool in_half_plane(half_plane hp, pt q) {
  double eval = hp.l.a*q.x + hp.l.b*q.y + hp.l.c;
  if (hp.neg) { return eval <=  EPS; }
  else        { return eval >= -EPS; }
}

/*
 * half plane intersection
 */

vector<pt> intersect_half_planes(vector<half_plane> half_planes) {
  int n = half_planes.size();
  vector<pt> pts;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      pt p = intersect(half_planes[i].l, half_planes[j].l);
      bool fail = false;
      for (int k = 0; k < n; k++) {
        if (!in_half_plane(half_planes[k], p)) { fail = true; }
      }
      if (!fail) { pts.push_back(p); }
    }
  }

  vector<pt> res = pts;
  if (pts.size() > 2) { pts = convex_hull(res); }
  return pts;
}

/*
 * max collinear points
 */

for (int i = 0; i < n; i++) {
  map<pair<int, int>, int> counts;
  for (int j = 0; j < n; j++) {
    if (i == j) { continue; }
    int rise = pts[j].y - pts[i].y;
    int run = pts[j].x - pts[i].x;
    if (run == 0) { counts[make_pair(1, 0)]++; }
    else {
      int g = gcd(abs(run), abs(rise));
      if (run < 0) { g *= -1; }
      counts[make_pair(rise/g, run/g)]++;
    }
  }

  for(auto cnt : counts) {
    res = max(res, cnt.second+1);
  }
}

/*
 * lawn
 */

typedef long double ld;

ld check(ld x) {
  ld ret = 0;
  for (int i = 0; i < n; i++) {
    ret = max(ret, distsqr(x, pts[i]));
  }
  return ret;
}

for (int it = 0; it < 70; it++) {
  ld mid1 = (hi + 2*lo)/3;
  ld mid2 = (2*hi + lo)/3;
  if (check(mid1) > check(mid2)) { lo = mid1; }
  else                           { hi = mid2; }
}

