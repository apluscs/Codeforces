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

int n, m;
vi adj[10000];
unordered_map<string, int> um;
unordered_map<int, int> common[10000];
string names[10000];
struct Solution {
  vi solve() {
    vi res(n);
    REP(i, n) {
      int count[10000] = {0};
      count[i] = -1;
      for (int j : adj[i])
        count[j] = -1;

      for (int j : adj[i]) {
        for (int k : adj[j]) {
          if (k != i && count[k] != -1) count[k]++;
        }
      }
      int best = 0;
      REP(j, n) {
        int c = count[j];
        if (c > best) best = c, res[i] = 0;
        if (c == best) res[i]++;
      }
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
  cin >> m;
  string s, t;
  REP(i, m) {
    cin >> s >> t;
    if (!um.count(s)) um[s] = n++;
    if (!um.count(t)) um[t] = n++;
    int a = um[s], b = um[t];
    names[a] = s, names[b] = t;
    adj[a].push_back(b), adj[b].push_back(a);
  }
  Solution test;
  auto res = test.solve();
  cout << res.size() << endl;
  REP(i, n)
  cout << names[i] << " " << res[i] << endl;
}