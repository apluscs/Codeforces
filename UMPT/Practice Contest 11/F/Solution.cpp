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

using namespace std;
const int mod = 1e9 + 7;

string str;
int n;
struct Solution {
  struct Node {
    int s, e, m;
    Node *left, *right;
    vector<int> frq;
    Node(int s, int e) : s(s), e(e), m((s + e) / 2), left(nullptr), right(nullptr) {
      frq.resize(26);
      if (s == e) {
        frq[str[s] - 'a'] = 1;
        return;
      }
      left = new Node(s, m), right = new Node(m + 1, e);
      frq = merge(left->frq, right->frq);
    }
    vector<int> update(int i, int oc, int nc) {
      // cout << i << "," << oc << "," << nc << endl;
      if (i < s || i > e) return frq;
      frq[nc]++, frq[oc]--;
      if (left) left->update(i, oc, nc), right->update(i, oc, nc);  // if you are leaf, stop
      return frq;
    }
    vector<int> query(int fr, int to) {
      if (fr > to) return vector<int>(26);
      if (fr == s && to == e) {
        return frq;
      }
      return merge(left->query(max(fr, s), min(to, m)), right->query(max(m + 1, fr), min(to, e)));
    }
    vector<int> merge(vector<int> a, const vector<int>& b) {
      REP(i, 26)
      a[i] += b[i];
      return a;
    }
  };
  Node* root;
  Solution() {
    root = new Node(0, n - 1);
  }
  void update(int i, int c) {
    // cout << c << "___" << endl;
    root->update(i, str[i] - 'a', c - 'a');
    str[i] = c;
  }
  int solve(int l, int r) {
    auto frq = root->query(l, r);
    int res = 0;
    for (int f : frq) res += f != 0;
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> str;
  n = str.length();
  int Q;
  cin >> Q;
  Solution test;
  int type, x, y;
  char c;
  while (Q--) {
    cin >> type >> x;
    if (type == 2) {
      cin >> y;
      cout << test.solve(x - 1, y - 1) << endl;
    } else {
      cin >> c;
      test.update(x - 1, c);
    }
  }
}