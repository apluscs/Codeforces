#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
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

int n, A[100000];
struct Solution {
  string solve() {
    ll sum = 0;
    string res(n, '+');
    FORD(i, n - 1, 0) {
      if (sum >= A[i])
        sum -= A[i], res[i] = '+';
      else
        sum = A[i] - sum, res[i] = '-';  // negate signs going forward
    }
    // cout << res << endl;
    int x = 1;
    REP(i, n) {
      if (res[i] == '+')
        res[i] = x < 0 ? '+' : '-';
      else
        res[i] = x > 0 ? '+' : '-', x = -x;
    }
    // dbg(sum);
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
  int x;
  REP(i, n)
  cin >> A[i];  // attach index to value
  Solution test;
  cout << test.solve() << endl;
}