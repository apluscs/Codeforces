#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;

int n, m;
vector<string> words;
string key;

struct Solution {
  void solve() {
    int res = 0;
    auto good = get_good();
    for (char c = 'a'; c <= 'z'; ++c) {
      if (key.find(c) != -1) continue;
      bool all_ok_words = true;
      for (string w : good) {
        bool found = false;
        // cout << w << " ";
        for (int i = 0; i != n; ++i) {
          if (key[i] == '*' && w[i] == c) {
            found = true;
            break;
          }
        }
        if (!found) {
          all_ok_words = false;
          break;
        }
      }
      res += all_ok_words;
      // if (all_ok_words) cout << string(1, c) << " ";
    }
    cout << res << endl;
  }

  vector<string> get_good() {
    vector<string> res;
    unordered_set<char> ks;
    for (auto c : key) ks.insert(c);
    for (string w : words) {
      bool ok = true;
      for (int i = 0; i != n; ++i) {
        if (w[i] != key[i] && key[i] != '*' ||
            key[i] == '*' && ks.count(w[i])) {
          ok = false;
          break;
        }
      }
      if (ok) {
        res.push_back(w);
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> key >> m;
  words.resize(m);
  for (int i = 0; i != m; ++i) {
    cin >> words[i];
  }
  Solution test;
  test.solve();
}