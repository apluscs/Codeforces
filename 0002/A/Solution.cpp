#include <assert.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n;
vector<pair<string, int>> rounds;

struct Solution {
  string solve() {
    unordered_map<string, int> scores;
    for (auto pr : rounds) {
      string p = pr.first;
      int s = pr.second;
      scores[p] += s;
    }
    int best = INT_MIN;
    for (auto p : scores) {
      best = max(p.second, best);
    }
    auto tops = get_best(scores, best);
    scores.clear();
    for (auto pr : rounds) {
      string p = pr.first;
      int s = pr.second;
      scores[p] += s;
      if (tops.count(p) && scores[p] >= best) {
        return pr.first;
      }
    }
    assert(0);
    return "";
  }

  unordered_set<string> get_best(unordered_map<string, int>& scores, int best) {
    unordered_set<string> res;
    for (auto p : scores) {
      if (p.second == best) res.insert(p.first);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  rounds.resize(n);
  for (int i = 0; i != n; ++i) {
    string p;
    int s;
    cin >> p >> s;
    rounds[i] = make_pair(p, s);
  }
  Solution test;
  cout << test.solve() << endl;
}