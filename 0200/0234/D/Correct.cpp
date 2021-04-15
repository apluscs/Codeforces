#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define dbgarr(x, sz)                                             \
  for (int asdf = 0; asdf < (sz); asdf++) cout << x[asdf] << ' '; \
  cout << endl;
using namespace std;

const int maxn = 100 + 10;

int n, m, k, x, p;
bool fav[maxn];
int lower[maxn], upper[maxn];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d%d", &m, &k);
  memset(fav, 0, sizeof(fav));
  for (int i = 1; i <= k; i++) {
    scanf("%d", &x);
    fav[x] = true;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%*s");
    scanf("%d", &p);

    int a = 0, b = 0, c = 0;
    for (int j = 0; j < p; j++) {
      scanf("%d", &x);
      if (x == 0)
        b++;
      else if (fav[x])
        a++;
      else
        c++;
    }

    lower[i] = a + max(0, b - (m - k - c));
    upper[i] = min(a + b, k);
  }
  cout << "hi" << endl;
  dbgarr(lower, n+1);
  for (int i = 1; i <= n; i++) {
    bool die = false;
    bool must = true;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (upper[i] < lower[j]) die = true;
      if (lower[i] < upper[j]) must = false;
    }

    if (die)
      printf("1\n");
    else if (must)
      printf("0\n");
    else
      printf("2\n");
  }

  return 0;
}