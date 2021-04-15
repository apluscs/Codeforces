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

const int MAXN = 501, MAXM = 501, MAXB = 501;

int n, m, B, mod, A[MAXN], dp[MAXM][MAXB];
struct Solution {
  int solve() {
    int prev[MAXM][MAXB];
    REP(i, n) {
      swap(prev, dp);  // then overwrite dp
      fill_n(dp[0], B + 1, 1 % mod);
      REPN(j, m) {
        REP(b, B + 1) {  // using first i people to write j lines, bugs <= b
          ll x = b >= A[i] ? dp[j - 1][b - A[i]] : 0, y = prev[j][b];
          dp[j][b] = (x + y) % mod;
        }
      }
    }
    return dp[m][B];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> B >> mod;
  REP(i, n)
  cin >> A[i];
  Solution test;
  cout << test.solve() << endl;
}