#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n, m, i, j, k, l, r, mid, L, R, len, x;
int where[1000011], a[1000011], dl[1000011], tree[1000011];
long long s[1000011];
bool cmp(int x, int y) {
  return a[x] < a[y];
}
int lowbit(int x) {
  return x - (x & (x - 1));
}
void ins(int x) {
  while (x <= n) {
    tree[x]++;
    x += lowbit(x);
  }
}
int qsum(int x) {
  int ans = 0;
  while (x) {
    ans += tree[x];
    x -= lowbit(x);
  }
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i], dl[i] = i;
  sort(dl + 1, dl + n + 1, cmp);
  for (i = 1; i <= n; i++) {
    l = 1, r = dl[i];
    while (l != r) {
      mid = (l + r) / 2;
      if (qsum(dl[i]) - qsum(mid - 1) == 0)
        r = mid;
      else
        l = mid + 1;
    }
    L = l;
    l = dl[i], r = n;
    while (l != r) {
      mid = l + r - (l + r) / 2;
      if (qsum(mid) - qsum(dl[i] - 1) == 0)
        l = mid;
      else
        r = mid - 1;
    }
    R = r;
    ins(dl[i]);
    if (dl[i] - L < R - dl[i])
      x = dl[i] - L + 1, len = R - dl[i];
    else
      x = R - dl[i] + 1, len = dl[i] - L;
    for (j = 1; j <= x; j++)
      s[j] += a[dl[i]], s[j + len + 1] -= a[dl[i]];
  }
  for (i = 1; i <= n; i++)
    s[i] += s[i - 1];
  cin >> m;
  for (i = 1; i <= m; i++) {
    cin >> k;
    printf("%.11f\n", s[k] / (double)(n - k + 1));
  }
  return 0;
}
