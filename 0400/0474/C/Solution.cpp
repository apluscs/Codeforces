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

int n, holes[4][4];
struct Solution {
  pii pos[4];
  int solve() {
    int res = 256;
    vector<vi> pts(4);
    REP(i, 256) {
      int x = i, t = 0;
      REP(j, 4)
      pts[j] = turn(x % 4, j), t += x % 4, x /= 4;
      // dbg(t);
      if (is_square(pts)) res = min(res, t);
    }
    pts = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    // cout << is_square(pts) << endl;
    return res == 256 ? -1 : res;
  }
  vi turn(int t, int i) {  // turn holes[i] t times ccw
    int a = holes[i][2], b = holes[i][3], x = holes[i][0], y = holes[i][1];
    while (t--) {
      int xd = x - a, yd = y - b;
      x = a - yd, y = b + xd;
    }
    return {x, y};
  }
  bool is_square(vector<vi>& pts) {
    // for (auto& p : pts) dbgitem(p);
    for (int i = 0; i != 4; ++i) {
      vector<ll> dist;
      for (int j = 0; j != 4; ++j) {
        if (i == j) continue;
        dist.push_back(get_dist(pts[i], pts[j]));
      }
      sort(dist.begin(), dist.end());
      ll s = dist[0];
      // printf("i=%d, dist=%lld, %lld, %lld\n", i, dist[0], dist[1], dist[2]);
      if (!s || s != dist[1] || 2 * s != dist[2]) return false;
    }
    return true;
  }
  ll get_dist(vector<int>& p1, vector<int>& p2) {
    return (ll)(p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  Solution test;
  while (n--) {
    REP(i, 4) {
      REP(j, 4)
      cin >> holes[i][j];
    }
    cout << test.solve() << endl;
  }
}