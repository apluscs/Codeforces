#ifdef LOCAL
#include "../micro.hpp"
#else
#include <bits/stdc++.h>
#endif
#define fo(i, a, b) for (ll i = a; i < ll(b); i++)
#define fr(i, a, b) for (ll i = b - 1; i >= ll(a); i--)
#define al(x) begin(x), end(x)
#define ral(x) rbegin(x), rend(x)
#define I(x) \
  ll x;      \
  cin >> x;
#define this (*this)
#define ar array
#define vc vector
#define pb push_back
#define rs resize
#define is insert
#define vl vc<ll>
#define popcnt __builtin_popcountll
#define sp << " " <<
#define endl "\n"
using namespace std;
using namespace std::placeholders;
using ll = long long;
using ld = long double;
using pa = array<ll, 2>;
using ve = ar<ll, 3000>;
using mt = ar<ve, 3000>;
using pr = pair<ll, ll>;
using bt = bitset<64>;
#ifdef DEBUG
#include "../debug.h"
#else
#define dbg(x)
#define cerr \
  if (false) cerr
#endif
const ll M = 998244353, inf = 1e18;
istream& operator>>(auto& is, auto& v) {
  for (auto& x : v) {
    cin >> x;
  }
  return is;
}
template <typename... Ts>
istream& operator>>(auto& is, pair<Ts...>& p) {
  return is >> p.first >> p.second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);
  I(y);
  I(x);
  string key;
  cin >> key;
  for (auto& va : key) {
    va -= '0';
  }
  dbg(x);
  dbg(y);
  vc<string> a(x);
  cin >> a;
  fo(i, 0, x) {
    fo(j, 0, y) {
      a[i][j] -= '0';
    }
  }
  vc cach(x, vc(y, vl(key.size() + 2, inf)));
  auto chk = [&](ll i, ll j) {
    return 0 <= i && i < x && 0 <= j && j < y;
  };
  function<ll(ll, ll, ll)> dp = [&](const ll i, const ll j, ll pos) -> ll {
    // returns best starting from (i,j)
    // direction is i-1, j+1
    // hop
    dbg(i);
    dbg(j);
    dbg(pos);
    if (!(chk(i, j))) {
      return inf;
    }
    auto& val = cach[i][j][pos];
    if (val != inf) {
      return val;
    }
    if (i == 0 && j == y - 1) {
      // Done
      return val = a[i][j];
    }
    // make a step

    val = min(val, a[i][j] + dp(i - 1, j, pos));
    val = min(val, a[i][j] + dp(i, j + 1, pos));
    // do a hop
    if (pos < key.size()) {
      /*fo(di, 0, 11){
				const auto dj = key[pos]+1-di;
				if(dj < 0){continue;}
				dbg(di);dbg(dj);
				val = min(val, a[i][j]+dp(i-di, j+dj, pos+1));
			}*/
      val = min(val, a[i][j] + dp(i - key[pos] - 1, j, pos + 1));
      val = min(val, a[i][j] + dp(i, j + key[pos] + 1, pos + 1));
    }
    return val;
  };
  ll ans = dp(x - 1, 0, 0);
  cout << ans << endl;
}
