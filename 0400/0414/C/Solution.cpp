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

const int MAXN = 1 << 20;

int n, A[MAXN];
vi l(MAXN), r(MAXN);
ll invs[21][2];
bool state[21];
struct Solution {
  Solution() {
    count(0, (1 << n) - 1, n);
    // REPN(i, n) {
    //   dbgarr(invs[i], 2);
    // }
  }
  void count(int s, int e, int h) {  // h = height
    if (s == e) return;
    int m = (s + e) / 2, i = s, j = m + 1, k = s;
    count(s, m, h - 1), count(m + 1, e, h - 1);
    FORN(i, s, m)
    r[i - s] = A[i];
    FORN(i, m + 1, e)
    l[i - m - 1] = A[i];
    invs[h][1] += count(s, e), swap(l, r), invs[h][0] += count(s, e);
    // dbg2(s, e);
  }
  ll count(int s, int e) {
    ll res = 0;
    int m = (s + e) / 2 - s, i = 0, j = 0, k = s;
    while (k <= e) {
      if (i > m)
        A[k++] = r[j++];
      else if (j > m)
        A[k++] = l[i++];
      else if (r[j] < l[i])  // both in range
        A[k++] = r[j++], res += m - i + 1;
      else {
        A[k++] = l[i++];
      }
    }
    // dbgarr(l, m+1)
    return res;
  }
  ll solve(int q) {
    // dbg(q);
    ll res = 0;
    REPN(i, q)
    state[i] = !state[i];
    REPN(i, n)
    res += invs[i][state[i]];
    // ;, printf("state[%d]= %d\n", i, state[i]);

    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  scanf("%d", &n);
  REP(i, 1 << n)
  scanf("%d", &A[i]);
  // iota(A, A + (1 << 20), 1);
  Solution test;
  int m, q;
  scanf("%d", &m);
  // dbg(m);
  while (m--) {
    scanf("%d", &q);
    printf("%lld\n", test.solve(q));
  }
}