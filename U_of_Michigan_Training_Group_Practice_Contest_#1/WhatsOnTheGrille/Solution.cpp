#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int n;
vector<string> grille;
string code;

struct Solution {
  struct pair_hash {
    template <class T1, class T2>
    size_t operator()(pair<T1, T2> const &pair) const {
      size_t h1 = std::hash<T1>()(pair.first);
      size_t h2 = std::hash<T2>()(pair.second);

      return h1 ^ h2;
    }
  };
  string solve() {
    unordered_set<pair<int, int>, pair_hash> vis;
    vector<pair<int, int>> holes;
    vector<string> grid(n, string(n, ' '));
    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != n; ++j) {
        if (grille[i][j] == '.') {
          holes.push_back(make_pair(i, j));
        }
      }
    }
    if (holes.size() == 0 || holes.size() == n * n) return "invalid grille";
    int cp = 0;
    sort(holes.begin(), holes.end());
    for (auto p : holes) {
      int i = p.first, j = p.second;
    }
    for (int cycle = 0; cycle * holes.size() < n * n; ++cycle) {
      vector<pair<int, int>> nextholes;
      for (auto p : holes) {
        int i = p.first, j = p.second;
        vis.insert(p);
        // cout<<i<<","<<j<<"\t";
        grid[i][j] = code[cp++];
        nextholes.push_back(clockwise(i, j));
      }
      sort(nextholes.begin(), nextholes.end());
      holes = nextholes;
      // cout<<endl;
    }
    if (vis.size() != n * n) return "invalid grille";
    string res = "";
    for (int i = 0; i != n; ++i) {
      res += grid[i];
    }
    return res;
  }

  pair<int, int> clockwise(int i, int j) { return make_pair(j, n - i - 1); }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  grille.resize(n);
  for (int i = 0; i != n; ++i) {
    cin >> grille[i];
  }
  cin >> code;
  Solution test;
  cout << test.solve();
}