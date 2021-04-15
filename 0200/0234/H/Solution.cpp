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

int n, m;
bool A[100000], B[100000];

struct Solution {
  pair<vi, vi> solve() {
    vi order, turns;
    // dbg(n);
    for (int i = n - 1, j = m - 1, p = -1; i != -1 || j != -1;) {  // p = prev card (from bottom)
      if (i == -1) {
        order.push_back(j + n), p = B[j--];
        continue;
      }
      if (j == -1) {
        order.push_back(i), p = A[i--];
        continue;
      }
      if (A[i] == p)
        order.push_back(i--);
      else if (B[j] == p)
        order.push_back(j-- + n);
      else if (A[i] == 0)  // none equal p
        order.push_back(i--), p = 0;
      else
        order.push_back(j + n), p = B[j--];
    }
    reverse(order.begin(), order.end());
    int p = -1;
    for (int i = 0; i != n + m; ++i) {  // p = prev card (from top)
      int x = order[i] < n ? A[order[i]] : B[order[i] - n];
      if (x != p && p != -1) turns.push_back(i - 1);
      p = x;
    }
    if (p == 1) turns.push_back(n + m - 1);  // turn them all to down
    return {order, turns};
  }
};
void print(vector<int>& nums, ofstream& fout) {
  for (auto num : nums) fout << num + 1 << " ";
  fout << endl;
}

int main() {
  ifstream fin;
  ios::sync_with_stdio(false);
  fin.open("input.txt");
  fin >> n;
  REP(i, n)
  fin >> A[i];
  fin >> m;
  REP(i, m)
  fin >> B[i];
  ofstream fout;
  fout.open("output.txt");
  Solution test;
  auto res = test.solve();
  print(res.first, fout);
  fout << res.second.size() << endl;
  print(res.second, fout);
}