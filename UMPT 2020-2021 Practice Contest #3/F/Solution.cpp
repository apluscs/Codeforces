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

int x2;
struct Solution {
    vector<bool> sv;
    int solve() {
        sv = sieve(x2);
        int res = INT_MAX;
        auto primes = get_primes(x2);
        auto xs = get_xs(primes, x2);
        // for (auto p : xs) cout << p << " ";
        // cout << endl;
        for (auto x1 : xs) {
            primes = get_primes(x1);
            for (auto p : primes) {
                int x0 = x1 - p + 1;
                // printf("x1=%d, p=%d, x0=%d\n", x1, p, x0);
                if (x0 <= p) continue;
                res = min(res, x0);
            }
        }
        return res;
    }
    unordered_set<int> get_xs(vector<int> primes, int high) {
        unordered_set<int> res;
        int p = *max_element(primes.begin(), primes.end());
        for (int x = high; x != high - p && x > p; x--) {
            if (sv[x]) continue;  // x's need to be composite
            res.insert(x);
        }
        return res;
    }
    vector<int> get_primes(int n) {
        vector<int> res;
        int root = sqrt(n);
        for (int i = 2; i <= root; ++i) {
            if (n % i == 0) {
                if (sv[i]) res.push_back(i);
                int other = n / i;
                if (sv[other]) res.push_back(other);
            }
        }
        return res;
    }
    vector<bool> sieve(int n) {
        vector<bool> prime(n + 1, true);
        prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        return prime;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x2;
    Solution test;
    auto res = test.solve();
    cout << res << endl;
}