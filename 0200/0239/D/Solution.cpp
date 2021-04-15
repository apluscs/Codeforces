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

int n, h;
pair<int, int> a[200005];
struct Solution {
  pair<int, vector<int>> solve() {
    if (n == 2) return {0, {1, 1}};
    sort(a, a + n);  // sort based on value
    vector<int> res(n, 1);
    int h1 = a[n - 1].first + a[n - 2].first, l1 = a[0].first + a[1].first,  // if everything in one set
        h2 = max(h1, h + a[n - 1].first + a[0].first), l2 = min(l1 + h, a[1].first + a[2].first);
    if (h1 - l1 < h2 - l2) return {h1 - l1, res};
    res[a[0].second] = 2;
    return {h2 - l2, res};
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
  cin >> n >> h;
  int x;
  REP(i, n) {
    cin >> x, a[i] = {x, i};
  }
  Solution test;
  auto res = test.solve();
  cout << res.first << endl;
  print(res.second);
}