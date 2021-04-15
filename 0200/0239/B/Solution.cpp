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

int n, Q;
struct Solution {
  vector<int> solve(string s) {
    vector<int> res(10);
    int i = 0, d = 1;
    while (i >= 0 && i < s.length()) {
      if (isdigit(s[i])) {
        res[s[i] - '0']++;
        if (s[i] == '0') {
          s.erase(s.begin() + i);
          i = d == -1 ? i - 1 : i;  // erased, so don't increment
        } else {
          s[i]--;
          i += d;
        }
      } else {
        d = s[i] == '>' ? 1 : -1;
        if (i + d >= 0 && i + d < s.length() && !isdigit(s[i + d])) {
          s.erase(s.begin() + i);
          if (d == -1) i--;
        } else
          i += d;
      }
      // printf("i=%d, s=%s\n", i, s.c_str());
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
  string s;
  cin >> n >> Q >> s;
  Solution test;
  int l, r;
  while (Q--) {
    cin >> l >> r;
    l--, r--;
    auto res = test.solve(s.substr(l, r - l + 1));
    print(res);
  }
}