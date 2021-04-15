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

int k;
string s;
struct Solution {
  string solve() {
    int frq[26] = {0}, n = s.length(), m = n / k;  // each part is length m
    if (n % k) return "-1";
    for (char c : s) frq[c - 'a']++;
    REP(i, 26)
    if (frq[i] % k) return "-1";
    string res;
    while (k) {
      REP(i, 26) {
        char c = i + 'a';
        int f = frq[i] / k;
        while (f--) res += c, frq[i]--;
      }
      // cout << res << endl;
      k--;
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
  cin >> k >> s;
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}