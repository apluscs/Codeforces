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

const int mod = 1e9 + 7;

int n, stock[2], h[200], dp[200][40001][2];

struct Solution {
  int solve() {
    memset(dp, -1, sizeof(dp));
    return solve(0, stock[0], stock[1], 2);  // no color came before it
  }
  int solve(int i, int r, int g, int p) {  // p = prev color (to the left)
    // cout << i << endl;
    if (r < 0 || g < 0) return 1e9;  // not possible
    if (i == n) return 0;
    // dbg(p);
    if (dp[i][r][p] != -1) return dp[i][r][p];
    int a = solve(i + 1, r - h[i], g, 0) + (p == 1 ? min(h[i], h[i - 1]) : 0),
        b = solve(i + 1, r, g - h[i], 1) + (p == 0 ? min(h[i], h[i - 1]) : 0);
    return dp[i][r][p] = min(a, b);
  }
};
int main() {
  ifstream fin;
  ios::sync_with_stdio(false);
  fin.open("input.txt");
  fin >> n >> stock[0] >> stock[1];
  REP(i, n)
  fin >> h[i];
  ofstream fout;
  fout.open("output.txt");
  Solution test;
  auto res = test.solve();
  // dbg(res);
  fout << (res == 1e9 ? -1 : res) << endl;
}