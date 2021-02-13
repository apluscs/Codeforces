#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
vector<pair<int, int>> a[N];

long long dfs(int x, int ep, int parent = -1) {
  long long total = 0;

  vector<int> thr;
  for (auto it : a[x]) {
    int y = it.first;
    int c = it.second;
    if (y != parent) {
      total += dfs(y, c, x);
      thr.push_back(c);
    }
  }
  sort(thr.begin(), thr.end());
  long long sum = 0;
  for (int t : thr) sum += t;
  if (!thr.empty() && thr.back() - ep > sum - thr.back()) {
    total += thr.back() - ep;
  } else if (sum > ep) {
    total += (sum - ep + 1) / 2;
  }
  printf("x=%d, total=%d\n", x, total);
  return total;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    a[x].push_back({y, c});
    a[y].push_back({x, c});
  }
  long long ans = dfs(0, 0);
  cout << ans << endl;
  return 0;
}