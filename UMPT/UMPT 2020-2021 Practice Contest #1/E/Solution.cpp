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

int n, m;
vector<string> ss;
struct Solution {
    string solve() {
        string res = "", mid = "";
        vector<int> partners(n, -1);
        for (int i = 0; i != n; ++i) {  // assign partner for string i
            auto rev = ss[i];
            reverse(rev.begin(), rev.end());
            // cout<<rev<<endl;
            for (int j = 0; j != n && partners[i] == -1; ++j) {
                if (i == j || partners[j] != -1) continue;
                if (rev == ss[j]) {
                    partners[i] = j;
                    partners[j] = i;
                }
            }
        }
        for (int i = 0; i != n; ++i) {
            if (partners[i] != -1){
                if(partners[i]>i)res += ss[i];
                continue;
            }
            else if (is_palindrome(ss[i]))
                mid = ss[i];
        }
        auto temp = res;
        reverse(temp.begin(), temp.end());
        return res + mid + temp;
    }
    bool is_palindrome(string& str) {
        int j = str.length() - 1;
        for (int i = 0; i < j; i++, j--) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    cin >> n >> m;
    ss.resize(n);
    for (int i = 0; i != n; ++i) {
        cin >> ss[i];
    }
    Solution test;
    auto res = test.solve();
    cout << res.length() << endl;
    cout << res << endl;
}