#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
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

const int mod = 1000000009;

int n, up[200005], down[200005], up_total = 0;
vector<int> adj[200005];
struct Solution {
  int solve() {
    int res = n - 1;  // change all edges
    // dbgarr(down, n + 1);
    REPN(i, n) {
      for (int j : adj[i]) {  // edge between (i, j)
        if (j < 0) continue;  // don't double your work
        fill_n(up, n + 1, 0), fill_n(down, n + 1, 0), up_total = 0;
        dfs(i, j, 0, 0);  // subtree rooted at i
        int curr = 0, x = n;
        REPN(k, n) {
          x = min(x, up_total + down[k] - up[k]);
        }
        fill_n(up, n + 1, 0), fill_n(down, n + 1, 0), up_total = 0, curr = x;
        dfs(j, i, 0, 0), x = n;  // subtree rooted at j
        REPN(k, n) {
          x = min(x, up_total + down[k] - up[k]);
        }
        res = min(res, curr + x);
      }
    }
    return res;
  }
  void dfs(int i, int par, int d, int u) {
    // dbg(i);
    down[i] = d, up[i] = u;
    for (int j : adj[i]) {
      if (abs(j) == par) continue;
      d += (j > 0), u += (j < 0);
      dfs(abs(j), i, d, u);
      d -= (j > 0), u -= (j < 0);
      up_total += (j < 0);
    }
  }
};
void print(vector<int>& nums) {
  for (auto num : nums) cout << num << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  int a, b;
  FOR(i, 1, n) {
    cin >> a >> b, adj[a].push_back(b), adj[b].push_back(-a);  // -a to signify reversed of original edge
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}