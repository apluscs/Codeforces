#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define dbg(x) cout << (#x) << " is " << (x) << endl;
#define dbg2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << y << endl;
#define dbgarr(x, sz)                                             \
  for (int asdf = 0; asdf < (sz); asdf++) cout << x[asdf] << ' '; \
  cout << endl;
#define dbgarr2(x, rose, colin)                \
  for (int asdf2 = 0; asdf2 < rose; asdf2++) { \
    dbgarr(x[asdf2], colin);                   \
  }
#define dbgitem(x)                                                           \
  for (auto asdf = x.begin(); asdf != x.end(); asdf++) cout << *asdf << ' '; \
  cout << endl;

const int mod = 1000000009;

int n, m;
struct Solution {
  map<int, set<int>> ranges;
  int s, e = -1;
  unordered_map<int, int> um;
  set<int> inds;
  Solution() : s(n) {}
  int solve(int i) {
    int first = inds.empty() ? n : *inds.begin() - 1, last = inds.empty() ? n : n - *inds.rbegin(), br = ranges.empty() ? 0 : ranges.rbegin()->first, j;  // br = best range
    // cout << i << endl;
    if (first >= last && first >= br / 2)
      j = 1;
    else if (last > br / 2)
      j = n;
    else {
      auto it = ranges.rbegin();
      if (it != ranges.rend()) it++;  // try and see if there is one less
      int x = it == ranges.rend() || it->first / 2 != br / 2 ? n : *it->second.begin();
      int s = min(*ranges.rbegin()->second.begin(), x);  // min index with this range
      j = s + br / 2;
    }  // now place it at j
    // if (i == 91593) print_ranges();
    um[i] = j;
    printf("%d at %d\n", i, j);
    if (inds.empty()) {
      inds.insert(j);
      return j;
    }
    if (j == 1) {
      int k = *inds.upper_bound(j);  // next one, can create range of length k-j
      ranges[k - j].insert(j);       // j = smaller index
    } else if (j == n) {
      auto it = inds.lower_bound(j);
      it--;
      int k = *it;  // range k ---- j
      // printf("k=%d, j=%d\n", k, j);
      ranges[j - k].insert(k);
    } else {  // are separating existing range
      auto it = inds.lower_bound(j);
      int e = *it;
      it--;
      int s = *it;  // range s ---- j ---- e
      ranges[e - s].erase(s), ranges[j - s].insert(s), ranges[e - j].insert(j);
      if (ranges[e - s].empty()) ranges.erase(e - s);
    }
    inds.insert(j);
    return j;
  }
  void depart(int i) {
    int j = um[i];
    auto it = inds.upper_bound(j);
    int e = it == inds.end() ? -1 : *it, s = -1;
    it--;
    printf("%d left\n", j);
    if (it != inds.begin()) {  // some one preceding
      it--, s = *it;
    }
    if (s != -1) {  // someone comes before
      ranges[j - s].erase(s);
      if (ranges[j - s].empty()) ranges.erase(j - s);
    }
    if (e != -1) {  // someone comes before
      ranges[e - j].erase(j);
      if (ranges[e - j].empty()) ranges.erase(e - j);
    }
    if (s != -1 && e != -1) {  // both neighbors, must make new range
      ranges[e - s].insert(s);
    }
    inds.erase(j);
  }
  void print_inds() {
    for (int s : inds) printf("%d ", s);
    printf("\n");
  }
  void print_ranges() {
    for (auto& p : ranges) {
      printf("len=%d: ", p.first);
      for (int s : p.second) printf("%d ", s);
      printf("\n");
    }
  }
};
void print(vector<int>& nums) {
  for (auto num : nums) cout << num << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  // cin.tie(0);
  cin >> n >> m;
  Solution test;
  int t, id;
  while (m--) {
    cin >> t >> id;
    // if (n == 399 && m <= 199999 - 100) cout << t << " " << id << endl;
    if (t == 1) {
      int x = test.solve(id);
      // if (n != 399) cout << x << endl;
      printf("%d\n", x);
    } else {
      test.depart(id);
    }
  }
}