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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXH = 894, MAXN = 2e5;

int dp[MAXN + 1], R, G;
struct Solution {
  int solve() {
    int prev[MAXN + 1] = {0};
    dp[0] = 1;
    REPN(i, MAXH) {        // i = height
      bool found = false;  // if exists a valid tower at this height
      swap(prev, dp);
      REP(j, R + 1) {  // using this many red blocks
        found |= dp[j] = ((j >= i ? prev[j - i] : 0) + (i * (i + 1) / 2 - j <= G ? prev[j] : 0)) % mod;
      }
      // dbg(i);
      // dbgarr(dp, R+1);
      if (!found) break;
    }
    // dbgarr(prev, R+1);
    return accumulate(prev, prev + R + 1, 0LL) % mod;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> G;
  Solution test;
  cout << test.solve() << endl;
}