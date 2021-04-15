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

const int mod = 1000000009;

int n, k;
string s;
struct Solution {
  pair<int, string> solve() {
    string t = s;
    int x = solve(s);
    if (k > 2)
      return {x, s};  // the original solved
    t[0] = t[0] == 'A' ? 'B' : 'A';
    int y = solve(t)+1;
    return x < y ? make_pair(x, s) : make_pair(y, t);
  }
  int solve(string& t) {
    int res = 0;
    FOR(i, 1, n) {                           // replace s[i] with something != s[i+1] if s[i] == s[i-1]
      char c = i == n - 1 ? '.' : t[i + 1];  // next one
      if (t[i] == t[i - 1]) {
        t[i] = c;  // just in case, at least it's != t[i-1]
        // printf("i=%d, t=%s\n", i, t.c_str());
        REP(j, k) {
          if (c - 'A' != j && t[i - 1] - 'A' != j) {
            // printf("i=%d, t=%s, j=%d\n", i, t.c_str(), j);
            t[i] = char(j + 'A');
            // printf("i=%d, t=%s, j=%d\n", i, t.c_str(), j);
            break;
          }
        }
        res++;
      }
    }
    // printf("t=%s, res=%d\n", t.c_str(), res);
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
  cin >> n >> k >> s;
  Solution test;
  auto res = test.solve();
  cout << res.first << endl
       << res.second << endl;
}