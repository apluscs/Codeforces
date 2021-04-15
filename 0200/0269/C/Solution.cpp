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

const int mod = 1e9 + 7;

struct E {
  int u, v, c;
  E() {}
  E(int u, int v, int c) : u(u), v(v), c(c) {}
} Es[200000];
int n, m, in_flow[200000];
vi adj[200000];

struct Solution {
  vi solve() {
    REP(i, n)
    in_flow[i] /= 2;  // now this is accurate
    in_flow[0] = 0;
    vi res(m);
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int i : adj[u]) {
        int v = Es[i].u + Es[i].v - u, c = Es[i].c;
        // dbg2(u, v);
        if (v != n - 1 && !in_flow[v]) continue;  // already processed, but let sink slide
        res[i] = u == Es[i].u ? 0 : 1;            // if flipped, record
        if (!(in_flow[v] -= c) && v != n - 1) que.push(v);  // sink should not send out
      }
    }
    return res;
  }
};

void print(vector<int>& nums) {
  for (auto num : nums) cout << num << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int u, v, c;
  REP(i, m)
  cin >> u >> v >> c, adj[--u].push_back(i), adj[--v].push_back(i), Es[i] = E(u, v, c), in_flow[u] += c, in_flow[v] += c;
  Solution test;
  auto res = test.solve();
  print(res);
}