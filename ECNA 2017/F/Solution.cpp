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
#include <set>
#include <stack>
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
#define print_arr(arr, n) \
  REP(i, n)               \
  cout << arr[i] << " ";  \
  cout << endl;

using namespace std;
const int mod = 1e9 + 7;

int n;
vector<int> adj[10001];
int sizes[10001];
struct Solution {
  pair<int, int> solve() {
    dfs_sizes(0, -1);
    // print_arr(sizes, n + 1);
    return dfs(0, -1);
  }
  pair<int, int> dfs(int i, int p) {
    int sum = n - sizes[i] + 1, n1 = 0, h1 = sum, h2 = 0;  // start tree above as 'first kid'
    for (int j : adj[i]) {
      if (j == p) continue;
      n1 += sizes[j] * sum;  // each node in j is paired with every node that came before it
      sum += sizes[j];
      if (sizes[j] >= h1)
        h2 = h1, h1 = sizes[j];
      else if (sizes[j] > h2)
        h2 = sizes[j];
    }
    pair<int, int> res = {n1, n1 - h2 * h1};
    // printf("i=%d, n1=%d, n2=%d\n", i, n1, res.second);
    for (int j : adj[i]) {
      if (j == p) continue;
      res = max(res, dfs(j, i));
    }
    return res;
  }
  int dfs_sizes(int i, int p) {
    sizes[i] = 1;
    for (int j : adj[i]) {
      if (j == p) continue;
      sizes[i] += dfs_sizes(j, i);
    }
    // printf("i=%d, res=%d\n", i, sizes[i]);
    return sizes[i];
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  int a, b;
  Solution test;
  REP(i, n) {
    cin >> a >> b;
    adj[a].push_back(b), adj[b].push_back(a);
  }
  auto res = test.solve();
  cout << res.first << " " << res.second << endl;
}