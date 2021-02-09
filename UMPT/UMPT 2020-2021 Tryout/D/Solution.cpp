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
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)

using namespace std;
const int mod = 1e9 + 7;

int n, m, k;
vector<vector<int>> adj;
struct Solution {
  int solve() {
    int res = 0;
    for (int i = 2; i <= k + 2; ++i) {
      res += bfs(i);
    }
    return res;
  }
  int bfs(int s) {
    queue<int> que;
    vector<bool> vis(n + 1);
    que.push(s), vis[s] = true;
    int res = 0;
    while (!que.empty()) {
      for (int z = que.size(); z; --z) {
        int x = que.front();
        printf("x=%d\n", x);
        que.pop();
        if (x == 1) return res;
        for (int y : adj[x]) {
          if (!vis[y]) {
            que.push(y), vis[y] = true;
          }
        }
      }
      res++;
    }
    return -1;  // should never happen
  }
  void print(vector<int>& nums) {
    for (auto num : nums) cout << num << " ";
    cout << endl;
  }
  void print(vector<vector<int>>& nums) {
    for (auto& row : nums) print(row);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  adj.clear(), adj.resize(n + 1);
  int a, b;
  REP(i, n) {
    cin >> a >> b;
    adj[a].push_back(b);
  }
  Solution test;
  auto res = test.solve();
  cout << res << endl;
}
