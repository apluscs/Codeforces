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

int n, ac, bc;  // one count, two count
struct Solution {
    vector<int> solve() {
        auto prime = sieve(ac + bc * 2);
        // for (auto p : prime) cout << p << " ";
        // cout << endl;
        vector<int> res;
        int curr = 0;
        while (ac || bc) {
            if (ac == 0) {
                bc--;
                res.push_back(2);
                curr += 2;
                continue;
            }
            if (bc == 0) {
                ac--;
                curr++;
                res.push_back(1);
                continue;
            }
            if (prime[curr + 1]) {
                ac--;
                curr++;
                res.push_back(1);
            } else {
                bc--;
                curr += 2;
                res.push_back(2);
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
    cin >> n;
    ac = bc = 0;
    for (int i = 0; i != n; ++i) {
        int x;
        cin >> x;
        if (x == 1)
            ac++;
        else
            bc++;
    }
    Solution test;
    for (auto num : test.solve()) cout << num << " ";
    cout << endl;
}