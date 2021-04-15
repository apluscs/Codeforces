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

int n, m, k, known[101], unknown[101], known_not[101];
vi actors[101];
bool fav[101];

struct Solution {
  vi solve() {
    int max_known = 0, max_potential = 0, ub[101], lb[101];
    REP(i, n) {
      max_potential = max(max_potential, ub[i] = min(k, known[i] + unknown[i]));
      max_known = max(max_known, lb[i] = known[i] + unknown[i] - min(m - known_not[i] - k, unknown[i]));
    }
    // dbgarr(ub, n);
    // dbgarr(lb, n);
    vi res(n);
    REP(i, n) {
      bool best = true, worst = false;  // best if no one else's ub > your lb, worst if someone's lower bound > your ub
      REP(j, n) {
        if (i == j) continue;
        if (ub[j] > lb[i])
          best = false;
        if (ub[i] < lb[j])
          worst = true;
      }
      res[i] = worst ? 1 : best ? 0
                                : 2;
    }
    return res;
  }
};
int main() {
  ifstream fin;
  ios::sync_with_stdio(false);
  fin.open("input.txt");
  fin >> m >> k;
  int x, D;
  REP(i, k) {
    fin >> x, fav[x] = true;
  }
  fin >> n;
  string s;
  REP(i, n) {
    fin >> s >> D;
    while (D--) fin >> x, actors[i].push_back(x), known[i] += fav[x], known_not[i] += !fav[x] && x, unknown[i] += x == 0;
    // , cout << x << endl;
  }

  ofstream fout;
  fout.open("output.txt");
  Solution test;
  auto res = test.solve();
  for (int r : res) fout << r << endl;
}