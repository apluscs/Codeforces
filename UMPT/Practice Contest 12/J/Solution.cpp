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

int n, res[300001];
vector<int> kids[300001];
struct Solution {
  set<pair<int, int>> solve(int i) {  // <subtree size, index it came from>
    set<pair<int, int>> curr;
    for (int j : kids[i]) {
      auto temp = solve(j);
      if (temp.size() > curr.size()) swap(temp, curr);  // want curr to be larger
      curr.insert(temp.begin(), temp.end());
    }
    curr.insert({curr.size() + 1, i});  // mark yourself
    int x = curr.size();
    // printf("i=%d\n", i);
    // print(curr);
    res[i] = curr.lower_bound({(x + 1) / 2, 0})->second;
    return move(curr);
  }
  void print(set<pair<int, int>>& curr) {
    for (auto& p : curr) printf("(%d, %d) ", p.first, p.second);
    printf("\n");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, x;
  cin >> n >> T;
  FOR(i, 1, n) {
    cin >> x;  // parent of node i
    kids[--x].push_back(i);
  }
  Solution test;
  test.solve(0);
  while (T--) {
    cin >> x, x--;
    cout << res[x] + 1 << endl;
  }
}