#include <assert.h>
#include <float.h>
#include <math.h>

#include <algorithm>
#include <climits>
#include <functional>
#include <iomanip>
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

int n, k;
struct Solution {
    vector<int> cap, res;
    vector<int> solve() {
        res.clear();
        res.resize(n);
        for (int i = 0; i != n; ++i) res[i] = i + 1;
        bool a=solve(0, n - 1, k - 1);
        if(a)return res;
        return {};
    }
    bool solve(int s, int e, int w) {  // w = how much work to be done
        if (w == 0) return true;       // no work necessary
        int m = e - s + 1, mid = (s + e-1) / 2;
        if (w % 2 || (m <= 1)) return false;  // w is odd OR too much work
        swap(res[mid],res[mid+1]);  // get them out of order, but keep two halves in order
        w = (w - 2) / 2;                      // work for each subcall
        int w1 = w, w2 = w;
        if (w % 2) {
            w1--;
            w2++;  // these must be even
        }
        bool a = solve(s, mid, w1), b = solve(mid + 1, e, w2);
        return a && b;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    Solution test;
    auto res = test.solve();
    if (res.empty()) {
        cout << -1 << endl;
        return 0;
    }
    for (auto r : res) cout << r << " ";
    cout << endl;
}