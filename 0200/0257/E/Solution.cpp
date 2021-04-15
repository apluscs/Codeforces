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

const int mod = 1e9 + 7, MAXM = 2e5 + 5;
struct P {
  int t, s, f, i;
  P() {}
  P(int t, int s, int f, int i) : t(t), s(s), f(f), i(i) {}
  void print() { printf("t=%d, s=%d, f=%d\n", t, s, f); }
} Ps[100000];
vector<P> fm[MAXM], wm[MAXM];  // fm = on elevator, waiting for floor i; wm = on floor waiting for elevator
int n, m, tree[MAXM];          // tree = BIT tracking floor counts
struct compar {
  bool operator()(const P& a, const P& b) const {
    return a.t > b.t;  // earliest at the top
  }
};
struct Solution {
  map<int, int> fs;  // fs[i] = #people waiting on / waiting for floor i
  vector<ll> solve() {
    priority_queue<P, vector<P>, compar> pre(Ps, Ps + n);  // not even begun waiting yet
    ll t = 1, f = 1;
    // REP(i, n)
    // Ps[i].print();
    vector<ll> res(n);
    while (!pre.empty() || !fs.empty()) {
      ll t1 = pre.empty() ? LLONG_MAX : pre.top().t, nf;           // time next person begins to wait
      int d = query(f + 1, MAXM - 1) >= query(1, f - 1) ? 1 : -1;  // direction to head in
      if (fs.empty())
        nf = LLONG_MAX, d = 0;  // no next floor so don't move
      else if (d > 0)
        nf = fs.upper_bound(f)->first;  // next higher floor
      else {
        auto it = fs.lower_bound(f);
        it--, nf = it->first;  // next lower floor
      }
      // printf("t1=%lld, nf=%lld, d=%d\n", t1, nf, d);
      if (abs(nf - f) < t1 - t) // we get to next floor first 
        t += abs(nf - f), f = nf;  
      else
        f += d * (t1 - t), t = t1;  // interrupted by someone who started waiting
      // printf("t=%lld, f=%lld\n", t, f);

      while (!pre.empty() && pre.top().t == t) {
        auto p = pre.top();
        pre.pop(), update(p.s, 1), wm[p.s].push_back(p);  // started to wait on this floor
      }                                                   // not everyone has been dropped off
      for (P& p : fm[f]) res[p.i] = t;                    // record what time p got off
      update(f, -fm[f].size()), fm[f].clear();            // these people have no effect
      for (P& p : wm[f]) fm[p.f].push_back(p), update(p.f, 1);
      update(f, -wm[f].size()), wm[f].clear();  // no longer waiting ON this floor
    }

    return res;
  }
  void update(int v, int d) {  // d is the incoming change
    if ((fs[v] += d) == 0) fs.erase(v);
    for (int i = v; i < MAXM; i += (i & -i)) tree[i] += d;
  }
  int count(int v) {
    int res = 0;
    for (int i = v; i; i -= (i & -i)) res += tree[i];
    // printf("v=%d, count=%d\n", v, res);
    return res;
  }
  int query(int l, int r) {
    return count(r) - count(l - 1);
  }
};

void print(vector<ll>& nums) {
  for (auto num : nums) cout << num << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int t, s, f;
  REP(i, n) {
    cin >> t >> s >> f;
    Ps[i] = P(t, s, f, i);
  }
  Solution test;
  auto res = test.solve();
  print(res);
}