#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int x, a, b, c, n;
vector<pair<int, string>> nums;

struct Solution {
  void solve() {
    sort(nums.begin(), nums.end());
    // for (auto p : nums) cout << p.first << "," << p.second << endl;
    ofstream outfile;
    outfile.open("output.txt");
    int m = n / 4;
    char group = 'A';
    while (m--) {
      outfile << "Group " << string(1, group++) << ":\n";
      for (int i = 4; i != 0; --i) {
        int offset = i * (m + 1);
        int j = (-next_num() % (m + 1)) - 1 + offset;
        auto p = nums[j];
        outfile << p.second << endl;
        nums.erase(nums.begin() + j);
      }
    }
  }
  int next_num() {
    x = (x * a + b) % c;
    // cout << x << endl;
    return x;
  }
};

int main() {
  ifstream infile;
  infile.open("input.txt");
  ios::sync_with_stdio(false);
  infile >> n >> x >> a >> b >> c;
  string s;
  nums.clear();
  for (int i = 0, score; i != n; ++i) {
    infile >> s >> score;
    nums.push_back(make_pair(score, s));
  }
  Solution test;
  test.solve();
}
