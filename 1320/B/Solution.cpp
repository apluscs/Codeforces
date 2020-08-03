#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (ll i = 0; i < n; i++)
#define repr(i, k, n) for (ll i = k; i < n; i++)
#define repr_r(i, n) for (ll i = n - 1; i >= 0; i--)
#define ll long long

using namespace std;
const int mod = 1e9 + 7;

int n, m, k;
vector<int> path;
vector<vector<int>> adj, radj;
struct Solution {
  vector<int> dist, count;
  int tar;
  void solve() {
    tar = path.back();
    bfs();
    int must = 0, might = 0;
    repr(i, 1, k) {
      int curr = path[i], pre = path[i - 1];
      if (dist[curr] >= dist[pre]) {
        must++;
        continue;
      }
      for (auto nei : radj[pre]) {
        if (nei != curr && dist[nei] == dist[curr]) {
          might++;
          break;
        }
      }
    }
    cout << must << " " << might + must << endl;
  }
  void bfs() {
    dist.resize(n, -1);
    count.resize(n); // count[i] = how many nodes are i dist away from tar
    queue<int> que;
    que.push(tar);
    dist[tar] = 0, count[0] = 1;
    while (!que.empty()) { // set the dist before you add to queue
      int i = que.front();
      que.pop();
      for (auto fr : adj[i]) {
        if (dist[fr] != -1)
          continue;
        dist[fr] = 1 + dist[i];
        count[dist[fr]]++;
        que.push(fr);
      }
    }
    // rep(i, n) cout << dist[i] << " ";
    // cout << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    cin >> n >> m;
    adj.resize(n);
    radj.resize(n);
    int u, v;
    rep(i, m) {
      cin >> u >> v; // adj[i]=all nodes leading into i
      adj[--v].push_back(--u);
      radj[u].push_back(v);
    }
    cin >> k;
    path.resize(k);
    rep(i, k) {
      cin >> u;
      path[i] = --u;
    }
    Solution test;
    test.solve();
  }
}
