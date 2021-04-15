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
struct T {
  ll sum = 0, v1 = 0, v2 = 0;
  int s, m, e;
  T *left = nullptr, *right = nullptr;
  T(int s, int e) : s(s), e(e), m((s + e) / 2) {}
  void update(int f, int t, ll d1, ll d2) {
    if (f > t)
      return;
    // dbg2(f,t);
    if (f == s && t == e) {
      // if(t==4) dbg2(d1,d2);
      v1 += d1, v2 += d2;
    } else {
      if (!left) {  // emergency build
        left = new T(s, m), right = new T(m + 1, e);
      }
      left->update(max(f, s), min(t, m), d1, d2);
      right->update(max(f, m + 1), min(t, e), d1, d2);
    }
  }
  pii query(int f, int t) {  // internal version, you don't use
    if (f > t)
      return {0, 0};
    if (f == s && t == e || !left)
      return {v1, v2};
    auto la = left->query(max(f, s), min(t, m)), ra = right->query(max(f, m + 1), min(t, e));
    return {v1 + la.first + ra.first, v2 + la.second + ra.second};
  }
};
int n, m, A[MAXN], res[MAXN], lb[MAXN], ub[MAXN];
struct Solution {
  T* root = new T(1, n);
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
    // dbgarr(lb, n);
    // dbgarr(ub, n);
    REP(i, n) {
      ll L = i - lb[i] + 1, R = ub[i] - i + 1;
      if (L > R) swap(L, R);
      // dbg2(L, R);
      root->update(1, L, 0, A[i]), root->update(L + 1, R, A[i] * L, 0), root->update(R + 1, R + L, (R + L) * A[i], -A[i]);
    }
  }
  double solve(int k) {
    // dbg(k);
    auto p = root->query(k, k);
    // dbg2(p.first, p.second);
    return (p.first + k * p.second) / double(n - k + 1);
  }
};
void free(T* curr) {
  if (curr->left) free(curr->left), free(curr->right);
  delete curr;
}
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
    cout << test.solve(k) << '\n';
  }
  // free(test.root);
}