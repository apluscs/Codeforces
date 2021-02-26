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

int n, m, tree[10005];
struct Node {
  int x1, y1, x2, y2;

  bool operator<(const Node& y) {  // sort by second x
    return x1 < y.x1;
  }
};
Node horz[5001], vert[5001];
struct Solution {
  ll solve() {
    ll res = 0;
    sort(horz + 1, horz + n + 1), sort(vert + 1, vert + m + 1);
    for (int i = 1; i <= m; ++i) {  // right side
      memset(tree, 0, sizeof(tree));
      vector<int> q;
      for (int j = 1; j <= n; ++j)
        if (horz[j].x1 <= vert[i].x1 && horz[j].x2 >= vert[i].x1 && horz[j].y1 >= vert[i].y1 && horz[j].y2 <= vert[i].y2) {
          // intersect with vert[i]
          update(horz[j].y1, 1);  // add height of this horz
          q.push_back(j);
        }
      int tail = q.size() - 1;
      for (int j = i - 1; j >= 1; --j) {                            // left side
        for (; tail >= 0 && horz[q[tail]].x1 > vert[j].x1; --tail)  // k 单调递增
          update(horz[q[tail]].y1, -1);                             //删去队列中不与 j 相交的竖线
        int l = max(vert[i].y1, vert[j].y1) - 1, r = min(vert[i].y2, vert[j].y2);
        if (l >= r) continue;           //两条线段有交
        ll curr = query(r) - query(l);  //[l, r] 区间内的竖线能与 i,j 组成矩形
        res += curr * (curr - 1) / 2;   //统计答案
      }
    }
    return res;
  }
  void update(int v, int d) {
    for (int i = v; i <= 10005; i += (i & -i)) tree[i] += d;
  }
  int query(int v) {
    int res = 0;
    for (int i = v; i; i -= (i & -i)) res += tree[i];
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, x1, y1, x2, y2;
  cin >> T, n = m = 0;
  while (T--) {
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 5001, y1 += 5001, x2 += 5001, y2 += 5001;  //防止出现负数
    if (y1 == y2)
      horz[++n] = (Node){min(x1, x2), y1, max(x1, x2), y2};
    else
      vert[++m] = (Node){x1, min(y1, y2), x2, max(y1, y2)};
  }
  Solution test;
  cout << test.solve() << endl;
}