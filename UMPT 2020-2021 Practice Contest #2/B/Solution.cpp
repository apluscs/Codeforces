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

string given;
vector<string> hand;
struct Solution {
    string solve() {
        for (auto h : hand) {
            if (h[0] == given[0] || h[1] == given[1]) return "YES";
        }
        return "NO";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> given;
    hand.resize(5);
    for (int i = 0; i != 5; ++i) {
        cin >> hand[i];
    }
    Solution test;
    cout << test.solve() << endl;
}