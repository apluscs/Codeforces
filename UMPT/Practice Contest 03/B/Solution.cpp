#include <assert.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;

ll n;
int k;
struct Solution {
    ll solve() {
        vector<ll> asc, dec;
        ll root = sqrt(n);
        for (ll i = 1; i <=root; ++i) {
            if (n % i == 0) {
                asc.push_back(i);
                dec.push_back(n / i);
            }
        }
        if (asc.back() == dec.back()) dec.pop_back();
        if (k <= asc.size()) return asc[k - 1];
        int x = dec.size() - (k - asc.size());
        // cout << x << endl;
        if (x < 0) {
            return -1;
        }
        return dec[x];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    Solution test;
    cout << test.solve() << endl;
}