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

const int mod = 1e9 + 7;
const double pi = 3.1415926535897932;

int n, pts[100000][2];
double A[200000];
struct Solution {
  double solve() {
    REP(i, n) {
      int x = pts[i][0], y = pts[i][1];
      A[i] = atan2(y, x) * 180 / pi, A[i + n] = A[i] + 360;  // convert to degrees
    }
    sort(A, A + 2 * n);
    double res = 360;
    FOR(i, n - 1, 2 * n) {
      res = min(res, A[i] - A[i - n + 1]);
    }
    return res;
  }
};
void print(vector<int>& nums) {
  for (auto num : nums) cout << num << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(11);
  cin >> n;
  REP(i, n)
  cin >> pts[i][0] >> pts[i][1];
  Solution test;
  cout << test.solve() << endl;
}
