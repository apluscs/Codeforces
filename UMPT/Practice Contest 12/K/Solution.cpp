#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define print_arr(arr, n) \
  REP(i, n)               \
  cout << arr[i] << " ";  \
  cout << endl;

using namespace std;
const int mod = 1e9 + 7;

struct V {
  int x, y1, y2;
  V() {}
  V(int x, int y1, int y2) : x(x), y1(y1), y2(y2) {}
  void print() {
    printf("x=%d, y1=%d, y2=%d\n", x, y1, y2);
  }
  bool operator<(const V& other) {  // by x
    return x < other.x;
  }
};
struct H {
  int x1, y, x2;
  H() {}
  H(int x1, int y, int x2) : x1(x1), y(y), x2(x2) {}
  bool operator<(const H& other) {  // by when they start
    return x1 < other.x1;
  }
  void print() {
    printf("x1=%d, x2=%d, y=%d\n", x1, x2, y);
  }
};

int n, m, tree[10005];
V vert[5001];
H horz[5001];
struct Solution {
  ll solve() {
    ll res = 0;
    sort(vert, vert + n);
    REP(i, n) {
      vector<H> hs;
      memset(tree, 0, sizeof(tree));
      REP(j, m) {  // find all horz that have right >= vert[i].x and add to hs and BIT for height range
        if (horz[j].x2 >= vert[i].x) {
          hs.push_back(horz[j]), update(horz[j].y, 1);
        }
      }
      sort(hs.begin(), hs.end());
      int h = hs.size() - 1;  // starts at H with largest left point
      FORD(j, i - 1, 0) {
        int crit_x = vert[j].x;
        while (h != -1 && hs[h].x1 > crit_x) update(horz[h--].y, -1);  // ignore anything that isn't left enough to cover vert[j]
        ll curr = query(min(vert[i].y2, vert[j].y2)) - query(max(vert[i].y1, vert[j].y1) - 1);
        if (curr <= 1) continue;
        res += curr * (curr - 1) / 2;
      }
    }
    return res;
  }
  void update(int v, int d) {
    v += 5001;
    for (int i = v; i <= 10005; i += (i & -i)) tree[i] += d;
  }
  int query(int v) {
    int res = 0;
    v += 5001;
    for (int i = v; i; i -= (i & -i)) res += tree[i];
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, x1, y1, x2, y2;
  cin >> T, n = m = 0;
  REP(i, T) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {  // vert
      vert[n++] = V(x1, min(y1, y2), max(y1, y2));
    } else {
      horz[m++] = H(min(x1, x2), y1, max(x1, x2));
    }
  }
  Solution test;
  cout << test.solve() << endl;
}