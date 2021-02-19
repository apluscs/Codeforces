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

int n, m, K;
vector<int> in[200001], out[200001];
int path[200001], dist[200001];
struct Solution {
  vector<int> solve() {
    bfs();
    int low = 0, high = 0;
    // print_arr(dist, n);
    // print_arr(path, K);
    // REP(i, K - 1) {
    //   int x = path[i], z = path[i + 1], best = INT_MAX, count = 0;
    //   if (dist[z] >= dist[x]) {
    //     low++, high++;
    //     continue;
    //   }
    //   for (int y : out[x]) {
    //     if (y != z && dist[y] == dist[z]) {
    //       high++;
    //       printf("i=%d\n", i);
    //       break;
    //     }
    //   }
    // }
    REP(i, K - 1) {
      int x = path[i], z = path[i + 1], best = INT_MAX, count = 0;
      for (int y : out[x]) {
        if (best > dist[y]) {
          count = 1, best = dist[y];
        } else if (best == dist[y]) {
          count++;
          // printf("best=%d, y=%d\n", best, y);
        }
      }
      if (dist[z] > best) low++, high++;  // had to rebuild
      else if (count > 1) {
        // printf("i=%d,x=%d,z=%d, best=%d, count=%d\n", i, x, z, best, count);
        high++;
      }
    }
    return {low, high};
  }
  /*i=2
i=4
i=10
i=11*/
  void bfs() {
    fill_n(dist, n, INT_MAX);
    dist[path[K - 1]] = 0;  // the source
    queue<int> que;
    que.push(path[K - 1]);
    while (!que.empty()) {
      int x = que.front();
      que.pop();
      // cout << x << "," << d << endl;
      for (int y : in[x]) {
        int nd = dist[x] + 1;
        if (dist[y] != INT_MAX) continue;  // alr processed
        que.push(y);
        dist[y] = nd;
      }
    }
  }
};
void print(const vector<int>& nums) {
  for (auto num : nums) cout << num << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int a, b;
  REP(i, m) {
    cin >> a >> b;
    a--, b--;
    in[b].push_back(a);
    out[a].push_back(b);
  }
  cin >> K;
  REP(i, K) {
    cin >> path[i];
    path[i]--;
  }
  Solution test;
  // print(out[10]);
  print(test.solve());
}