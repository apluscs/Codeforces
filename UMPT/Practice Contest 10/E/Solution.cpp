#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
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
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)

using namespace std;
const int mod = 1e9 + 7;

int n, m;
vector<pair<int, int>> adj[101];
struct Solution {
  int s, e;
  int solve(int s, int e) {
    this->s = s, this->e = e;
    int res = 0;
    REPN(c, m) {
      res += able(c);
    }
    return res;
  }
  bool able(int C) {
    bool vis[101] = {0};
    queue<int> que;
    que.push(s);
    vis[s] = true;
    while (!que.empty()) {
      int x = que.front();
      que.pop();
      if (x == e) return true;
      for (auto p : adj[x]) {
        if (p.second != C) continue;
        int y = p.first;
        if (vis[y]) continue;
        vis[y] = true;
        que.push(y);
      }
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int a, b, c, Q;
  REP(i, m) {
    cin >> a >> b >> c;
    a--, b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  Solution test;
  cin >> Q;
  while (Q--) {
    cin >> a >> b;
    a--, b--;
    cout << test.solve(a, b) << endl;
  }
}