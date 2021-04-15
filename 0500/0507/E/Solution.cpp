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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXN = 1e5;

int n, m;
pii good[MAXN];  // good[i] = {# good edges to get to i from 0, edge connecting i to par}
vi adj[MAXN];
bool in_path[MAXN];
struct E {
  int x, y, z;
  E() {}
  E(int x, int y, int z) : x(x), y(y), z(z) {}
} Es[MAXN];
struct Solution {
  vector<E> solve() {
    vector<E> res;
    queue<int> que;
    int dist[MAXN] = {1};
    que.push(0);
    while (!que.empty()) {
      for (int q = que.size(); q; --q) {
        int i = que.front();
        que.pop();
        // printf("%d ", i);
        for (int e : adj[i]) {
          int j = Es[e].x + Es[e].y - i, z = Es[e].z;
          if (dist[j] && dist[j] <= dist[i]) continue;  // only go to next level
          good[j] = max(good[j], {good[i].first + z, e});
          if (!dist[j]) que.push(j), dist[j] = dist[i] + 1;  // only push in if first time seeing it
        }
      }
      // printf("new layer\n");
    }
    int i = n - 1;
    while (i) {
      int e = good[i].second;
      i = Es[e].x + Es[e].y - i, in_path[e] = true;
    }
    REP(i, m) {
      if (in_path[i] && !Es[i].z || !in_path[i] && Es[i].z) res.push_back(Es[i]);
    }
    return res;
  }
};
void print(vector<E>& nums) {
  for (auto& c : nums) printf("%d %d %d\n", c.x + 1, 1 + c.y, 1 - c.z);  // flip the status
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  REP(i, m) {
    cin >> Es[i].x >> Es[i].y >> Es[i].z, adj[--Es[i].x].push_back(i), adj[--Es[i].y].push_back(i);
  }
  Solution test;
  auto res = test.solve();
  printf("%d\n", (int)res.size());
  print(res);
}