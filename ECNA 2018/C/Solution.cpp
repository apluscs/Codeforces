#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
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

using namespace std;
const int mod = 1e9 + 7;

int n, m;  // target, hole
vector<string> ballots;
vector<int> frq;
struct Solution {
  vector<vector<bool>> wins;  // wins[i][j] = if i wins over j
  vector<bool> solve() {
    vector<bool> res(n);
    precompute();
    // for (auto w : wins) {
    //   for (auto b : w) cout << b << " ";
    //   cout << endl;
    // }
    REP(i, n) {
      if (able(i)) res[i] = true;
    }
    return res;
  }
  bool able(int x) {  // is there an agenda s.t. x wins?
    vector<int> nums;
    vector<bool> vis(n);
    nums.pb(x);  // last in agenda
    vis[x] = true;
    int pos = 0;
    while (pos < nums.size()) {
      REP(i, n) {
        if (!vis[i] && wins[nums[pos]][i]) {
          nums.pb(i);
          vis[i] = true;
        }
      }
      pos++;
    }
    return nums.size() == n;  // able to make the whole agenda
  }
  void precompute() {
    wins.clear();
    wins.resize(n, vector<bool>(n));
    REP(i, n) {
      char ci = i + 'A';
      FOR(j, i, n) {
        char cj = j + 'A';
        int bal = 0;  // if bal>0, means i wins over j
        REP(k, m) {
          auto& b = ballots[k];
          int pi = b.find(ci), pj = b.find(cj);
          bal += pi < pj ? frq[k] : -frq[k];
        }
        wins[i][j] = bal > 0 ? true : false;
        wins[j][i] = !wins[i][j];  // only one can win
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  ballots.resize(m);
  frq.resize(m);
  REP(i, m) {
    cin >> frq[i] >> ballots[i];
  }
  Solution test;
  auto res = test.solve();
  REP(i, n) {
    char c = i + 'A';
    string r = res[i] ? "can win" : "can't win";
    printf("%c: %s\n", c, r.c_str());
  }
}