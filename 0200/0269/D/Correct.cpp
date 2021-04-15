#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define dbg(x) cout << (#x) << " is " << (x) << endl;
#define dbg2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << y << endl;
#define dbgitem(x)                                                    \
  for (auto asdf = x.begin(); asdf != x.end(); asdf++) asdf->print(); \
  cout << endl;
#define MAXN 100005

int inf = 2000000000;

struct segment {
  int h, l, r;
  segment() {}
  segment(int h, int l, int r) : h(h), l(l), r(r) {}
  bool operator<(const segment &s) const {
    return h < s.h;
  }
};

struct part {
  int l, r, f;
  segment s;
  part(int l, int r, int f, segment s) : l(l), r(r), f(f), s(s) {}
  bool operator<(const part &p) const {
    return l < p.l;
  }
  void print() const {
    printf("l=%d, r=%d, f=%d, h=%d\n", l, r, f, s.h);
  }
};

set<part> sweep;
segment s[MAXN];

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; i++) {
    int h, l, r;
    scanf("%d %d %d", &h, &l, &r);
    s[i] = segment(h, l, r);
  }
  s[n] = segment(t, -inf, inf);  // at the very top
  sort(s, s + n);

  part bottom(-inf, inf, inf, segment(0, -inf, inf));
  part left(-inf - 1, -inf, 0, segment(0, -inf - 1, -inf));
  part right(inf, inf + 1, 0, segment(0, inf, inf + 1));
  sweep.insert(bottom);
  sweep.insert(left);
  sweep.insert(right);
  for (int i = 0; i <= n; i++) {
    int h = s[i].h, l = s[i].l, r = s[i].r;
    dbg(h);
    part p(l, r, 0, s[i]);
    set<part>::iterator it = sweep.upper_bound(p), jt, kt;
    it--;  // first one <= p
    jt = it;
    set<part>::iterator lt = jt, rt = jt;
    lt--;                // left of it
    rt++;                // right of it so (lt, jt, rt)
    while (jt->l < r) {  // some overlap between jt and p
      // dbg2(jt->l, jt->r);
      if (!(lt->s.r > max(jt->s.l, l) && jt->s.h < lt->s.h && lt->s.h < h) &&  // lt catches from p
          !(rt->s.l < min(jt->s.r, r) && jt->s.h < rt->s.h && rt->s.h < h)) {  // rt catches from p
        p.f = max(p.f, min(jt->f, min(jt->s.r, r) - max(jt->s.l, l)));         // cand flow through jt
      } else
        cout << (lt->s.r > max(jt->s.l, l) && jt->s.h < lt->s.h && lt->s.h < h) << "," << jt->l<< endl;
      lt++;
      jt++;
      rt++;
    }

    kt = jt;
    kt--;
    part start = *it, end = *kt;  // start, end are inclusive bounds of what was erased

    sweep.erase(it, jt);  // everything that overlapped
    if (start.l < l) {
      sweep.insert(part(start.l, l, start.f, start.s));
    }
    if (end.r > r) {
      sweep.insert(part(r, end.r, end.f, end.s));
    }
    sweep.insert(p);
    dbgitem(sweep);
  }

  set<part>::iterator it = sweep.begin();
  it++;
  printf("%d\n", it->f);
}
