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

int N;  // # nodes
bool isa[500][500], hasa[500][500];
unordered_map<string, int> nodes;
struct Solution {
  Solution() {
    N = nodes.size();
    REP(k, N) {
      REP(i, N) {
        REP(j, N) {
          isa[i][j] = isa[i][j] || isa[i][k] && isa[k][j];
          hasa[i][j] = hasa[i][j] || hasa[i][k] && hasa[k][j] || isa[i][k] && hasa[k][j] || hasa[i][k] && isa[k][j];
        }
      }
    }
  }
  string solve(bool t, int S, int T) {
    if (t)
      return hasa[S][T] ? "true" : "false";
    else
      return isa[S][T] ? "true" : "false";
  }
};
int get_node(string s) {
  if (nodes.count(s)) return nodes[s];
  int x = nodes.size();
  return nodes[s] = x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string c1, t, c2;
  memset(isa, 0, sizeof(isa)), memset(hasa, 0, sizeof(hasa));
  REP(i, n) {
    cin >> c1 >> t >> c2;
    int x = get_node(c1), y = get_node(c2);
    isa[x][x] = isa[y][y] = true;
    if (t == "is-a")
      isa[x][y] = true;
    else
      hasa[x][y] = true;
  }
  Solution test;
  REPN(i, m) {
    cin >> c1 >> t >> c2;
    int x = get_node(c1), y = get_node(c2);
    printf("Query %d: %s\n", i, test.solve(t == "has-a", x, y).c_str());
  }
}