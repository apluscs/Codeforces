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

int n, k;
pii A[1000];
string type;

struct Solution {
  pair<int, vi> solve() {
    sort(A, A + n);
    vi res;
    int worst;
    REP(i, k) {
      auto p = A[n - i - 1];
      res.push_back(p.second + 1);
      worst = p.first;
    }
    return make_pair(worst, res);
  }
};
int main() {
  ifstream fin;
  ios::sync_with_stdio(false);
  fin.open("input.txt");
  fin >> n >> k;
  ofstream fout;
  fout.open("output.txt");
  int x;
  REP(i, n)
  fin >> x, A[i] = {x, i};
  Solution test;
  auto res = test.solve();
  fout << res.first << endl;
  for (auto num : res.second) fout << num << " ";
  fout << endl;
}