#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;

int n, m;

struct Solution {
  vector<vector<int>> adj;
  vector<int> reps;
  vector<int> rank;
  bool ok = true;
  void solve() {
    adj.resize(n + 1);
    rank.resize(n + 1);
    reps.resize(n + 1, -1);
    for (int i = 0, a, b; i != m; ++i) {
      cin >> a >> b;
      if (a < b)
        adj[a].push_back(b);
      else
        adj[b].push_back(a);
      int pa = find(a), pb = find(b);
      if (pa != pb) set_union(pa, pb);
    }
    vector<int> nodes(n + 1);
    vector<int> edges(n + 1);
    for (int i = 1; i <= n; ++i) {
      int pi = find(i);
      nodes[pi]++;
      edges[pi] += adj[i].size();
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      int k = nodes[i];
      if (!k) continue;
      ok &= (ll)edges[i] == (ll)k * (k - 1) / 2;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  void set_union(int pa, int pb) {
    if (rank[pa] >= rank[pb]) {
      rank[pa] += rank[pa] == rank[pb] ? 1 : 0;
      reps[pb] = pa;
    } else {
      reps[pa] = pb;
    }
  }
  int find(int a) {
    while (reps[a] != -1) a = find(reps[a]);  // with path compression
    return a;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  Solution test;
  test.solve();
}