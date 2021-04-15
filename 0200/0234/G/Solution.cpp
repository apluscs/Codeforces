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

int n;

struct Solution {
  vector<vi> solve() {
    vector<vi> res;
    int b = 1;
    while (true) {
      vi curr;
      // cout << b <<endl;
      REP(i, n) {
        if (b & i) curr.push_back(i + 1);
      }
      if (curr.empty()) break;
      res.push_back(curr), b <<= 1;
    }
    return res;
  }
};
int main() {
  ifstream fin;
  ios::sync_with_stdio(false);
  fin.open("input.txt");
  fin >> n;
  ofstream fout;
  fout.open("output.txt");
  Solution test;
  auto res = test.solve();
  fout << res.size() << endl;
  for (auto& row : res) {
    fout << row.size() << " ";
    for (int r : row) fout << r << " ";
    fout << endl;
  }
}