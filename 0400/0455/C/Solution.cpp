#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXN = 3e5;

int n, m, diam[MAXN], reps[MAXN], Q;
vi adj[MAXN];
struct Solution {
  Solution() {  // find diams of each region
    memset(reps, -1, sizeof(reps));
    REP(i, n) {
      for (int j : adj[i]) set_union(i, j);
    }
    REP(i, n)
    if (reps[i] == -1) diam[i] = get_diameter(i);
    // dbgarr(reps, n);
    // dbgarr(diam, n);
  }
  int find(int a) {
    if (reps[a] != -1) {
      return reps[a] = find(reps[a]);  // with path compression;
    }
    return a;
  }
  int get_diameter(int i) {  // returns diam from the region i is in
    i = farthest(i, 0, -1).second;
    return farthest(i, 0, -1).first;
  }
  pii farthest(int i, int d, int p) {  // returns {dist, node} farthest from i; d= dist from source node
    pii res = {d, i};
    for (int j : adj[i]) {
      if (j == p) continue;
      res = max(res, farthest(j, d + 1, i));
    }
    return res;
  }
  void set_union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) reps[pa] = pb;
  }
  int solve(int i) {  // diam in region of i
    return diam[find(i)];
  }
  void update(int a, int b) {  // query 2
    int pa = find(a), pb = find(b);
    if (pa == pb) return;
    reps[pa] = pb, diam[pb] = max(max(diam[pb], diam[pa]), (diam[pb] + 1) / 2 + (diam[pa] + 1) / 2 + 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> Q;
  int a, b;
  REP(i, m) {
    cin >> a >> b, adj[--a].push_back(--b), adj[b].push_back(a);
  }
  Solution test;
  while (Q--) {
    cin >> a >> b;
    if (a == 1)
      cout << test.solve(b - 1) << endl;
    else
      cin >> a, test.update(a - 1, b - 1);
  }
}