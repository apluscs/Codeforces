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
ll A[300001], B[300001], post[300001], pre[300001];
struct Solution {
  ll solve() {
    post[n - 1] = A[n - 1];  // post[i]= min bullets for [i:n-1]
    FORD(i, n - 2, 0) {
      post[i] = post[i + 1] + A[i] - min(B[i], A[i + 1]);
    }
    pre[0] = A[0];
    FOR(i, 1, n) {
      pre[i] = pre[i - 1] + A[i] - min(B[i - 1], A[i]);
    }
    ll res = post[0];  // if the first we kill is 0
    // print_arr(pre, n);
    // print_arr(post, n);
    FOR(i, 1, n) {
      ll curr = post[i] + pre[i - 1] - min(B[n - 1], A[0]);
      res = min(res, curr);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution test;
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    REP(i, n) {
      cin >> A[i] >> B[i];
    }
    cout << test.solve() << endl;
  }
}