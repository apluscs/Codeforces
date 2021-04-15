#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define dbg(x) cout << (#x) << " is " << (x) << endl;
#define dbg2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << y << endl;
#define dbgarr(x, sz)                                             \
  for (int asdf = 0; asdf < (sz); asdf++) cout << x[asdf] << ' '; \
  cout << endl;
#define dbgarr2(x, rose, colin)                \
  for (int asdf2 = 0; asdf2 < rose; asdf2++) { \
    dbgarr(x[asdf2], colin);                   \
  }
#define dbgitem(x)                                                           \
  for (auto asdf = x.begin(); asdf != x.end(); asdf++) cout << *asdf << ' '; \
  cout << endl;

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

double pts[3][2], pi = 2 * acos(0.0);
struct Solution {
  double solve() {
    auto a = dist(pts[0][0], pts[0][1], pts[1][0], pts[1][1]), b = dist(pts[2][0], pts[2][1], pts[1][0], pts[1][1]), c = dist(pts[0][0], pts[0][1], pts[2][0], pts[2][1]);
    double s = (a + b + c) / 2, r = a * b * c / (4 * sqrt(s * (s - a) * (s - b) * (s - c)));
    double A = acos((b * b + c * c - a * a) / (2 * b * c)), B = acos((a * a + c * c - b * b) / (2 * a * c)), C = acos((a * a + b * b - c * c) / (2 * a * b));
    double g = gcd(gcd(A, B), C), n = pi / g;
    // dbg(g);
    return r * r * n / 2 * sin(2 * pi / n);
  }
  double gcd(double x, double y) {
    return fabs(y) < 0.0001 ? x : gcd(y, fmod(x, y));
  }

  double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  REP(i, 3)
  cin >> pts[i][0] >> pts[i][1];
  Solution test;
  cout << fixed << setprecision(7) << test.solve() << endl;
}