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

const int mod = 1e9 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, MAXN = 3e5;

int n, k, D;
struct Solution {
  vector<vi> solve() {
    vector<vi> res(D, vi(n));
    ll y = 1;
    REP(d, D) {
      if (y >= n) break;  // dont' want to overflow
      y *= k;
    }
    if (n > y) return {};  // not enough days / buses
    REP(i, n) {
      int x = i;
      REP(d, D) {
        res[d][i]= x % k+1, x /= k;
      }
    }
    return res;
  }
};
void print(vector<int>& nums) {
  for (auto num : nums) printf("%d ", num);
  printf("\n");
}

void print(vector<vector<int>>& nums) {
  for (auto& row : nums) print(row);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> D;
  Solution test;
  auto res = test.solve();
  if (res.empty()) {
    printf("-1\n");
    return 0;
  }
  print(res);
}