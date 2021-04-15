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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n;
vector<pii> adj[100000];
struct Solution {
  vi res;
  bool solve(int i, int par) {
    bool b=false; // if we included a city
    for (auto& p : adj[i]) {
      int j = p.first, t = p.second;
      if (j == par) continue;
      bool x = solve(j, i);
      if (!x && t) res.push_back(j+1),b=true;
      b= b || x;
    }
    // dbg2(i,b);
    return b;
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
  int a, b, t;
  REP(i, n - 1) {
    cin >> a >> b >> t, t--, a--, b--, adj[a].push_back(mp(b, t)), adj[b].push_back(mp(a, t));
  }
  Solution test;
  test.solve(0, -1);
  cout << test.res.size() << endl;
  print(test.res);
}