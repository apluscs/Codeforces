#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)

using namespace std;
const int mod = 1e9 + 7;

int n;
vector<string> ss;
struct Solution {
  vector<int> vis;
  vector<vector<int>> adj;
  string solve() {
    adj.clear();
    adj.resize(26);
    for (int i = 1, j; i != n; ++i) {
      string a = ss[i - 1], b = ss[i];
      int m = min(a.length(), b.length());
      for (j = 0; j != m; ++j) {
        if (a[j] == b[j]) continue;
        int x = a[j] - 'a', y = b[j] - 'a';
        adj[x].push_back(y);  // points to what needs to be larger than you
        break;
      }
      if (j == m && a.length() > m) return "Impossible";
    }
    auto topo = topo_sort();
    if (topo.size() != 26) return "Impossible";
    string res;
    for (auto t : topo) {
      res += char(t + 'a');
    }
    return res;
  }

  vector<int> topo_sort() {
    vector<int> res, indegree(26);
    queue<int> que;
    for (int i = 0; i < 26; i++) {
      for (int j : adj[i]) {
        indegree[j]++;
      }
    }
    for (int i = 0; i < 26; i++)
      if (indegree[i] == 0)
        que.push(i);
    while (!que.empty()) {
      int curr = que.front();
      que.pop();
      res.push_back(curr);
      for (int j : adj[curr]) {
        indegree[j]--;
        if (indegree[j] == 0) {
          que.push(j);
        }
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  ss.resize(n);
  REP(i, n) {
    cin >> ss[i];
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}