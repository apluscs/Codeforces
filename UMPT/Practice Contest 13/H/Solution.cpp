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

int n, reps[150001], X[150001], Y[150001];
vector<int> adj[150001];
struct Solution {
  vector<int> res;
  vector<int> solve() {
    memset(reps, -1, sizeof(reps));
    REP(i, n - 1) {
      set_union(X[i], Y[i]);
    }
    dfs(find(1));  // the only root
    return res;
  }
  void dfs(int i) {
    res.push_back(i);
    for (auto j : adj[i]) dfs(j);
  }
  int find(int a) {
    if (reps[a] != -1) {
      return reps[a] = find(reps[a]);  // with path compression;
    }
    return a;
  }

  // normal union find
  void set_union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) {
      reps[pa] = pb;
      adj[pb].push_back(pa);  // parent point to kids
    }
  }
};
void print(vector<int> nums) {
  for (auto num : nums) cout << num << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  Solution test;
  REP(i, n - 1) {
    cin >> X[i] >> Y[i];
  }
  print(test.solve());
}