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

int n, m, nums[100001];
struct Solution {
  struct Node {
    int s, e, m, lazy = 0;
    Node *left, *right;
    ll res;
    Node(int s, int e) : s(s), e(e), m((s + e) / 2), left(nullptr), right(nullptr), res(0) {
    }
    int build() {
      if (s == e) return res = nums[s];
      left = new Node(s, m), right = new Node(m + 1, e);
      left->build(), right->build();
      return res = left->res + right->res;
    }
    ll mod_update(int fr, int to, int z) {
      if (fr > to) return res;
      cout << fr << "," << to << "," << z << "," << s << "," << e << endl;
      if (fr == s && to == e) {
        res %= z, lazy = !lazy ? z : min(lazy, z);
        return res;
      }
      return res = left->mod_update(max(fr, s), min(to, m), z) + right->mod_update(max(m + 1, fr), min(to, e), z);
    }
    ll assn_update(int i, int x) {
      if (i < s || i > e) return res;
      if (i == s) {
        return res = x;
      }  // otherwise need to call children, but make sure they are up to date
      if (lazy) left->mod_update(left->s, left->e, lazy), right->mod_update(right->s, right->e, lazy), lazy = 0;
      return res = left->assn_update(i, x) + right->assn_update(i, x);
    }
    ll query(int fr, int to) {
      if (fr > to) return 0;
      if (fr == s && to == e) {
        return res;
      }
      if (lazy) left->mod_update(left->s, left->e, lazy), right->mod_update(right->s, right->e, lazy), lazy = 0;
      return left->query(max(fr, s), min(to, m)) + right->query(max(m + 1, fr), min(to, e));
    }
  };
  Node* root;
  Solution() {
    root = new Node(0, n - 1);
    root->build();
  }
  ll solve(int fr, int to) {
    return root->query(fr, to);
  }
  void mod_update(int fr, int to, int z) {
    root->mod_update(fr, to, z);
  }
  void assn_update(int i, int x) {
    root->assn_update(i, x);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  REP(i, n)
  cin >> nums[i];
  int type, x, y, z;
  Solution test;
  REP(i, m) {
    cin >> type;
    if (type == 1) {
      cin >> x >> y;
      cout << test.solve(x - 1, y - 1) << endl;
    } else if (type == 2) {
      cin >> x >> y >> z;
      test.mod_update(x - 1, y - 1, z);
    } else {
      cin >> x >> y;
      test.assn_update(x - 1, y);
    }
  }
}