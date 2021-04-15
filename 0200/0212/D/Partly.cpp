#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define ll long long
typedef pair<ll, ll> pii;
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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXN = 1e6;
ll tree[4 * MAXN + 1][2];
int n, m, A[MAXN], res[MAXN], lb[MAXN], ub[MAXN];
struct Solution {
  void update(int v, int tl, int tr, int l, int r, ll d1, ll d2) {  // tl, tr are for this node in the tree; l,r are for the range to be updated
    if (l > r)
      return;
    if (l == tl && r == tr) {
      tree[v][0] += d1, tree[v][1] += d2;
    } else {
      int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, max(l, tl), min(r, tm), d1, d2);
      update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), min(r, tr), d1, d2);
    }
  }
  pii query(int v, int tl, int tr, int pos) {
    if (tl == tr)
      return {tree[v][0], tree[v][1]};
    int tm = (tl + tr) / 2;
    auto p = pos <= tm ? query(v * 2, tl, tm, pos) : query(v * 2 + 1, tm + 1, tr, pos);
    return {tree[v][0] + p.first, tree[v][1] + p.second};
  }
  Solution() {
    stack<int> st;
    REP(i, n) {
      while (!st.empty() && A[st.top()] >= A[i]) st.pop();  // get last index whose value <= A[i]
      lb[i] = st.empty() ? 0 : st.top() + 1, st.push(i);
    }
    st = stack<int>();
    FORD(i, n - 1, 0) {
      while (!st.empty() && A[st.top()] > A[i]) st.pop();  // get first index whose value <= A[i]
      ub[i] = st.empty() ? n - 1 : st.top() - 1, st.push(i);
    }
    dbgarr(lb, n);
    dbgarr(ub, n);
    REP(i, n) {
      ll L = i - lb[i] + 1, R = ub[i] - i + 1;
      if (L > R) swap(L, R);
      // dbg2(L, R);
      update(1, 1, n, 1, L, 0, A[i]), update(1, 1, n, L + 1, R, A[i] * L, 0), update(1, 1, n, R + 1, R + L, (R + L) * A[i], -A[i]);
    }
  }
  double solve(int k) {
    // dbg(k);
    auto p = query(1, 1, n, k);
    // dbg2(p.first, p.second);
    return (p.first + k * p.second) / double(n - k + 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  REP(i, n)
  cin >> A[i];
  Solution test;
  cin >> m;
  int k;
  cout << fixed << setprecision(15);
  REP(i, m) {
    cin >> k;
    cout << test.solve(k) << endl;
  }
}