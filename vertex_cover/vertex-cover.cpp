#include <assert.h>

#include <algorithm>
#include <bitset>
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
vector<vector<int>> adj;
struct Solution {
  void solve() {
    vector<string> res;
    int best = n;
    for (int i = 0; i != (1 << n); ++i) {
      bitset<13> bits(i);
      bool b = able(bits);
      if (b) {
        if (bits.count() < best) {
          res.clear();
          best = bits.count();
        }
        if (bits.count() == best) res.push_back(stringify(bits));
      }
    }
    for (auto r : res) cout << r << endl;
  }
  bool able(bitset<13>& bits) {
    unordered_set<int> vis;
    for (int i = 0; i != 13; ++i) {
      if (!bits[i]) continue;
      for (auto to : adj[i]) {
        int a = min(to, i), b = max(to, i);
        vis.insert(b * 100 + a);
      }
    }
    cout << bits.to_string() << "," << vis.size() << endl;
    return vis.size() == m;
  }
  string stringify(bitset<13>& bits) {
    string res;
    for (int i = 0; i != 13; ++i) {
      if (bits[i]) res += to_string(i) + " ";
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  adj.clear();
  adj.resize(n);
  for (int i = 0, a, b; i != m; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  printf("n=%d,m=%d\n", n, m);
  Solution test;
  test.solve();
}