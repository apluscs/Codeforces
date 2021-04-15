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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXN = 100000;

vector<pii> adj[MAXN];
int n, sweep[MAXN], tin[MAXN], tout[MAXN], up[MAXN][18], timer, l;
struct Solution {
  vi res;
  Solution() {
    timer = 0, l = ceil(log2(n)), res.resize(n - 1);
    dfs(0, 0);
  }
  void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
      up[v][i] = up[up[v][i - 1]][i - 1];
    for (auto& pr : adj[v]) {
      int u = pr.first;
      if (u != p)
        dfs(u, v);
    }
    tout[v] = ++timer;
  }
  bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
  }

  int lca(int u, int v) {
    if (is_ancestor(u, v))
      return u;
    if (is_ancestor(v, u))
      return v;
    for (int i = l; i >= 0; --i) {
      if (!is_ancestor(up[u][i], v))
        u = up[u][i];
    }
    return up[u][0];
  }
  int solve(int i, int par) {
    int sum = sweep[i];
    for (auto& pr : adj[i]) {
      int j = pr.first, e = pr.second;
      if (j == par) continue;
      sum += res[e] = solve(j, i);
    }
    return sum;
  }
  void update(int a, int b) {
    int anc = lca(a, b);
    sweep[anc] -= 2, sweep[a]++, sweep[b]++;
  }
};
void print(vector<int>& nums) {
  for (auto num : nums) cout << num << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n, memset(sweep, 0, sizeof(sweep));
  int a, b, F;
  REP(i, n - 1) {
    cin >> a >> b, a--, b--, adj[a].push_back(mp(b, i)), adj[b].push_back(mp(a, i));
  }
  Solution test;
  cin >> F;
  while (F--) {
    cin >> a >> b, a--, b--, test.update(a, b);
  }
  test.solve(0, -1);
  print(test.res);
}