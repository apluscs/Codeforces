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

using namespace std;
const int mod = 1e9 + 7;

int n;
vector<vector<int>> adj;
vector<int> order;
struct Solution {
  void solve() {
    vector<ll> res(n);
    for (int ki = 0; ki != n; ++ki) {
      int k = order[ki];
      for (int ii = 0; ii < n; ++ii) { // the nodes that have been added
        for (int ji = 0; ji < n; ++ji) {
          int i = order[ii], j = order[ji];
          if (i == j)
            continue;
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
          if (ii <= ki && ji <= ki)
            res[ki] += adj[i][j];
        }
      }
    }
    for (int i = n - 1; i != -1; --i)
      cout << res[i] << " ";
    cout << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    cin >> n;
    adj.clear();
    adj.resize(n, vector<int>(n));
    order.resize(n);
    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != n; ++j) {
        cin >> adj[i][j];
      }
    }
    for (int i = n - 1; i != -1; --i) {
      cin >> order[i];
      order[i]--;
    }
    Solution test;
    test.solve();
  }
}
